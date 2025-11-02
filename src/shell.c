#include "shell.h"

char *builtin_str[] = { "cd", "help", "exit", "pwd", "clear" };
int (*builtin_func[]) (char **) = { &tidesh_cd, &tidesh_help, &tidesh_exit, &tidesh_pwd, &tidesh_clear };

int tidesh_num_builtins() {
    return sizeof(builtin_str) / sizeof(char *);
}

int tidesh_execute(char **args) {
    if (args[0] == NULL) return 1;

    for (int i = 0; i < tidesh_num_builtins(); i++) {
        if (strcmp(args[0], builtin_str[i]) == 0) {
            return (*builtin_func[i])(args);
        }
    }
    return tidesh_launch(args);
}

int tidesh_launch(char **args) {
    pid_t pid = fork();
    int status;

    if (pid == 0) {
        if (execvp(args[0], args) == -1) perror("tidesh");
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("tidesh");
    } else {
        waitpid(pid, &status, WUNTRACED);
    }
    return 1;
}

void handle_sigint(int sig) {
    write(STDOUT_FILENO, "\nInterrupted.\n> ", 15);
}

void tidesh_loop(void) {
    char *line, **args;
    int status;
    char cwd[PATH_MAX];

    do {
        if (getcwd(cwd, sizeof(cwd)) != NULL)
            printf("%s > ", cwd);
        else
            printf("> ");

        line = tidesh_read_line();
        args = tidesh_split_line(line);
        status = tidesh_execute(args);

        free(line);
        free(args);
    } while (status);
}

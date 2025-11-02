#include "builtins.h"

int tidesh_cd(char **args) {
    if (args[1] == NULL) fprintf(stderr, "tidesh: expected argument to \"cd\"\n");
    else if (chdir(args[1]) != 0) perror("tidesh");
    return 1;
}

int tidesh_help(char **args) {
    printf("tidesh - a very soggy shell.\nBuilt-in commands:\n");
    for (int i = 0; i < tidesh_num_builtins(); i++) {
        printf("  %s\n", builtin_str[i]);
    }
    return 1;
}

int tidesh_pwd(char **args) {
    char cwd[PATH_MAX];
    if (getcwd(cwd, sizeof(cwd)) != NULL) printf("%s\n", cwd);
    else perror("tidesh");
    return 1;
}

int tidesh_clear(char **args) {
    printf("\033[H\033[J");
    return 1;
}

int tidesh_exit(char **args) {
    return 0;
}

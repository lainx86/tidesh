#include "io.h"

char *tidesh_read_line(void) {
    int bufsize = TIDESH_RL_BUFSIZE, position = 0;
    char *buffer = malloc(sizeof(char) * bufsize);
    int c;

    if (!buffer) {
        fprintf(stderr, "tidesh: allocation error\n");
        exit(EXIT_FAILURE);
    }

    while (1) {
        c = getchar();
        if (c == EOF || c == '\n') {
            buffer[position] = '\0';
            return buffer;
        } else {
            buffer[position++] = c;
        }

        if (position >= bufsize - 1) {
            bufsize += TIDESH_RL_BUFSIZE;
            buffer = realloc(buffer, bufsize);
            if (!buffer) {
                fprintf(stderr, "tidesh: allocation error\n");
                exit(EXIT_FAILURE);
            }
        }
    }
}

char **tidesh_split_line(char *line) {
    int bufsize = TIDESH_TOK_BUFSIZE, position = 0;
    char **tokens = malloc(bufsize * sizeof(char *));
    char *token;

    if (!tokens) {
        fprintf(stderr, "tidesh: allocation error\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, TIDESH_TOK_DELIM);
    while (token != NULL) {
        tokens[position++] = token;

        if (position >= bufsize) {
            bufsize += TIDESH_TOK_BUFSIZE;
            tokens = realloc(tokens, bufsize * sizeof(char *));
            if (!tokens) {
                fprintf(stderr, "tidesh: allocation error\n");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, TIDESH_TOK_DELIM);
    }

    tokens[position] = NULL;
    return tokens;
}

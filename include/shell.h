#ifndef TIDESH_SHELL_H
#define TIDESH_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <limits.h>

#include "io.h"
#include "builtins.h"

void handle_sigint(int sig);
void tidesh_loop(void);
int tidesh_launch(char **args);
int tidesh_execute(char **args);
int tidesh_num_builtins(void);

extern char *builtin_str[];
extern int (*builtin_func[]) (char **);

#endif

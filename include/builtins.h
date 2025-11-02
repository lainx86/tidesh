#ifndef TIDESH_BUILTINS_H
#define TIDESH_BUILTINS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>

int tidesh_cd(char **args);
int tidesh_help(char **args);
int tidesh_exit(char **args);
int tidesh_pwd(char **args);
int tidesh_clear(char **args);

int tidesh_num_builtins(void);
extern char *builtin_str[];

#endif

#ifndef TIDESH_IO_H
#define TIDESH_IO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TIDESH_RL_BUFSIZE 1024
#define TIDESH_TOK_BUFSIZE 64
#define TIDESH_TOK_DELIM " \t\r\n\a"

char *tidesh_read_line(void);
char **tidesh_split_line(char *line);

#endif

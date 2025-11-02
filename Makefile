CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
SRCS = src/main.c src/shell.c src/builtins.c src/io.c
OBJS = $(SRCS:.c=.o)
TARGET = tidesh

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJS) $(TARGET)

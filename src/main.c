#include "shell.h"

int main(int argc, char **argv) {
    signal(SIGINT, handle_sigint);
    tidesh_loop();
    return EXIT_SUCCESS;
}

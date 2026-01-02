#include "mash_body.h"
#include "constants.h"
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>


void main_loop(char *buffer, char **args) {
    char c;
    int done = 0;
    int i = 0;

    while (1) {
        while (done == 0) {
            int n = read(0, &c, 1);
            if (n <= 0) _exit(0);

            handle_input(c, buffer, args, &i, &done);
        }
        done = 0;

        if (args[0] == NULL) continue;

        if (strcmp(args[0], "exit") == 0) { 
            write(1, "\n", 1);
            break;
        }

        pid_t pid = fork();
        if (pid < 0) {
            write(2, MSG_UNKNOWN, MSG_UNKNOWN_SIZE); 
            continue;
        }

        if (pid == 0) {
            write(1, "\n", 1);
            execvp(args[0], args);

            write(2, MSG_ERROR, MSG_ERROR_SIZE); 
        } else {
            wait(NULL);
            for (int j = 0; j < ARGS_SIZE; j++) args[j] = NULL;
        }
    }
}
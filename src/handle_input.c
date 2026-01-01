#include "mash_body.h"
#include <unistd.h>
#include "constants.h"

/* 
 Cosas a manejar:
 Que pueda leer saltos de linea sin meter el comando, pero que al presionar enter, 
 se ejecute el comando.


*/

void handle_input(char c, char *buffer, char **args, int *i, int *done) {
    switch (c) {
        case 10:
            buffer[*i] = '\0';
            parser(buffer, args);
            *i = 0;
            *done = 1;
            break;

        case 127:
        case 8:
            if (*i > 0) {
                (*i)--;
                write(1, "\b \b", 3);
                buffer[*i+1] = '\0'; 
            }
            break;

        case 27: {
            char seq[2];
            if (read(0, &seq[0], 1) > 0 && read(0, &seq[1], 1) > 0) {
                if (seq[0] == '[') {
                    switch (seq[1]) {
                        case 'C':
                        if(buffer[*i] != '\0') {
                            write(1, "\x1b[C", 3);
                            (*i)++;
                        }
                            break;
                        case 'D':
                            if (*i > 0) {
                                write(1, "\x1b[D", 3);
                                (*i)--;
                            }
                            break;
                    }
                }
            }
            break;
        }

        case 9:
            break;

        default:
            if (*i < BUFFER_SIZE - 1) {
                buffer[(*i)++] = c;
                write(1, &c, 1);
            }
            break;
    }
}
// tty.h
#ifndef MASH_BODY_H
#define MASH_BODY_H

#include <termios.h>

void tty_setup(struct termios *original, struct termios *raw);
void tty_restore(const struct termios *original);
void parser(char *buffer, char **args);
void main_loop(char *buffer, char **args);
void handle_input(char c, char *buffer, char **args, int *i, int *done);
#endif

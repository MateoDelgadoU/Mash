#include "mash_body.h"
#include <unistd.h>

void tty_setup(struct termios *original, struct termios *raw){
  tcgetattr(STDIN_FILENO, original);
  *raw = *original;
  
  // ICANON, RAW & ISIG are = 0, inactive
  raw->c_lflag &= ~(ICANON | ECHO | ISIG);

  tcsetattr(STDIN_FILENO, TCSAFLUSH, raw);
}

void tty_restore(const struct termios *original){
  tcsetattr(STDIN_FILENO, TCSAFLUSH, original);
}

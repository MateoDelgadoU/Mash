#include<termios.h>
#include "mash_body.h"
#include "constants.h"

int main(){
  struct termios original, raw;
  char *args[ARGS_SIZE];
  char buffer[BUFFER_SIZE];
  
  tty_setup(&original, &raw);
  
  main_loop(buffer, args);

  tty_restore(&original);
    
  return 0;
}

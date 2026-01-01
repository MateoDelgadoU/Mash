#include "mash_body.h"
#include <stddef.h>

void parser(char *buffer, char **args){
  int arg_index = 0;
  int i;
  int word = 0;

  for(i = 0; buffer[i] != '\0'; i++){
    if(buffer[i] != ' ' && word == 0){
      args[arg_index] = &buffer[i];
      word = 1;
      arg_index++;
    }

    if(word == 1 && buffer[i] == ' '){
      buffer[i] = '\0';
      word = 0;
    }
  }

  args[arg_index] = NULL;

}

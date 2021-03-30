#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>	// for fork
#include <sys/types.h>	// for pid_t
#include <sys/stat.h>  //for mkfifo
#include <stdlib.h>	// for exit(1)
#include <string.h>	// for strlen
#include <sys/wait.h>	// for wait
#include "defs.h"

int main(int argc, char const *argv[]){
  pid_t pid;
  pid = fork();

  if(pid < 0){
    fprintf(stderr, "fork failed..\n");
  }else if(pid == 0){ //Assistant process
    assistant();
  }else{ //Manager process
    manager();
  }

  return 0;
}

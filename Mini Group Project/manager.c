#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>	// for fork
#include <sys/types.h>	// for pid_t
#include <sys/stat.h>  //for mkfifo
#include <stdlib.h>	// for exit(1)
#include <string.h>	// for strlen
#include <sys/wait.h>	// for wait
#include <fcntl.h> //for file stuff
#include "defs.h" //our definitions

/**
 * Author: Tyler Tucker
 * Email: <tyler.m.tucker@okstate.edu>
 * Date: March 15th, 2020
 * Program Description: This file takes input from the user and then puts it
 * together and sends it to the assistant for use until it is terminated
 */

void manager() {
  char temp[30];
  char toSend[93];
  int fd;
  char pipe[] = ".pipe";

  /* create the FIFO (named pipe) */
  mkfifo(pipe, 0666);

  // Open pipe as write only for the manager
  if((fd = open(pipe, O_WRONLY | O_CREAT)) < 0) perror("Pipe failure");

  while(TRUE){ //Get user info and put in a single character array
    printf("Hello, What employee would you like information on?\n");
    scanf("%[^\n]%*c", temp);
    strcat(toSend,  temp);
    strcat(toSend, ",");
    memset(temp, 0, sizeof(temp));

    printf("What is their job title?\n");
    scanf("%[^\n]%*c", temp);
    strcat(toSend,  temp);
    strcat(toSend, ",");
    memset(temp, 0, sizeof(temp));

    printf("What is their job status?\n");
    scanf("%[^\n]%*c", temp);
    strcat(toSend,  temp);
    memset(temp, 0, sizeof(temp));

    printf("You are looking for: %s\n", toSend);
    printf("The assistant will report back to you shortly in their terminal\n\n");

    //writing info to pipe for the assistant
    if(write(fd, toSend, sizeof(toSend) + 1) < 0) perror("Write Failure");
    memset(toSend, 0, sizeof(toSend));
    sleep(5);
  }

  // Close plpe
  close(fd);

  /* remove the FIFO */
  unlink(pipe);
}

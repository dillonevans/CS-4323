#ifndef PROCESS_H
#define PROCESS_H


typedef struct process
{
    unsigned int pid;
    int burstTime;
    int virtualRuntime;
} Process;

#endif
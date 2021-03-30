#ifndef DEFS_H
#define DEFS_H

#define BUFFER_SIZE 2048
#define MAX_MESSAGES 10
#define MAX_MSG_SIZE 2048
#define MSG_BUFFER_SIZE MAX_MSG_SIZE + 10
#define PERMISSIONS 0666
#define SHARED_MEMORY_SIZE sizeof(struct Item) * 100 + sizeof(char) * 26
#define SHARED_MEMORY_NAME "/mem"
#define TRUE 1
#define FALSE 0

typedef int bool;

struct Item
{
    int serialNumber;
    char giftName[256];
    double price;
    char storeName[256];
};

void customer(int i);
void helper();

#endif
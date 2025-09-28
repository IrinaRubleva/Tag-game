#ifndef PLAY_H
#define PLAY_H

//#define MAX_SIZE 50


typedef struct Field 
{
    int hight;
    int wide;
    int *arr;
}Field;


typedef struct History History;

History *create_history();
void free_history(History *buff);
int push(History *buff, int val);
int peek(History *buff);
int pop(History *buff);
int go_back(History *buff, Field *field);

#endif
#include "play_in_15.h"
#include <stdio.h>
#include "input.h"
#include <stdlib.h>
#include "logic.h"



struct History{
    int capacity;
    int top;
    int *hist_arr;
};


History *create_history(){
    History *buff = (History *)malloc(sizeof(History));
    if (buff == NULL) {
        printf("Ошибка выделения памяти\n");
        return NULL;
    }
    printf("Введите, сколько ходов нужно запоминать: \n");
    if(get_int_natur(&(buff->capacity)) == -1){
        free(buff);
        return NULL;
    }
    buff->capacity++;
    buff->hist_arr = (int *)calloc(buff->capacity, sizeof(int));
    if (buff->hist_arr == NULL) {
        printf("Ошибка выделения памяти\n");
        free(buff);
        return NULL;
    }
    buff->top = 0;
    return buff;
}

void free_history(History *buff){
    if(buff != NULL){
        free(buff->hist_arr);
        free(buff);
    }
}


int push(History *buff, int val){
    // if(buff == NULL){
    //     printf("Ошибка\n");
    //     return -1;
    // }
    if (buff->top == buff->capacity){
        for(int i = 0; i < buff->capacity-1;i++){
            buff->hist_arr[i] = buff->hist_arr[i+1];
        }
        buff->top--;
    }
    buff->hist_arr[buff->top++] = val;
    return 0;
}

int peek(History *buff){
    if (buff->top == 0){
        printf("Стек пуст\n");
        return -1;
    }
    return buff->hist_arr[buff->top-1];
}

int pop(History *buff){
    if (buff->top == 0){
        printf("Стек пуст\n");
        return -1;
    }
    buff->top--;
    return 0;
}


int go_back(History *buff, Field *field){
    if (buff->top <= 1){
        printf("Вернуться назад больше нельзя!\n");
        return 0;
    }
    else{
        swap(field, buff->hist_arr[(buff->top)-2], buff->hist_arr[buff->top-1]);
        if (pop(buff) == -1){
            return -1;
        }
    }
    return 0;
}

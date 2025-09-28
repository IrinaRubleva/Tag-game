#include "play_in_15.h"
#include "logic.h"
#include <stdio.h>
#include "input.h"
#include <stdlib.h>



typedef struct Node{
    int data;
    struct Node *next; 
}Node;

struct History{
    int capacity;
    int top;
    struct Node *head;
};


History *create_history(){
    History *buff = (History *)malloc(sizeof(History));
    if(buff == NULL){
        printf("Ошибка выделении памяти.\n");
        return NULL;
    }
    printf("Введите, сколько ходов запоминать: \n");
    get_int_natur(&buff->capacity); //добавить код ошибки
    buff->head = NULL;
    buff->top = 0;
    return buff;
}


void free_history(History *buff){
    if(buff != NULL){
        Node *curr = buff->head;
        while (curr != NULL){
            Node *tmp = curr;
            curr = curr->next;
            free(tmp);
        }
        free(buff);   
    }
}


int push(History *buff, int val){
    if (buff->top == buff->capacity){
        Node *tmp = buff->head;
        buff->head = buff->head->next;
        free(tmp);
        --buff->top;
    }
    Node *new_node = (Node *)malloc(sizeof(Node));
    if(new_node == NULL){
        printf("Ошибка выделения памяти.\n");
        return -1;  //возвращать код ошибки !!!
    }
    new_node->data = val;
    new_node->next = buff->head;
    new_node->next = buff->head;
    buff->head = new_node;
    ++buff->top;
    return 0;
}

int peek(History *buff){
    if(buff->top == 0){
        printf("Стек пуст.\n");
        return -1;
    }
    return buff->head->data;
}

int pop(History *buff){
    if(buff->top == 0){
        printf("Стек пуст.\n");
        return -1;
    }
    Node *tmp = buff->head;
    buff->head = buff->head->next;
    free(tmp);
    --buff->top;
    return 0;
}


int go_back(History *buff, Field *field){
    if (buff->top == 1){  
        printf("Вернуться назад больше нельзя!\n");
        return 0;
    }
    else{
        Node * tmp = buff->head->next;
        swap(field, buff->head->data, tmp->data);
        if(pop(buff) == -1){
            return -1;
        }
    }
    return 0;
}

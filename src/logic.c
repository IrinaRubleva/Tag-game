#include "logic.h"
#include "play_in_15.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void free_field(Field *field){
    free(field->arr);
    free(field);
}


int shift(History *buff, Field *field, int val){
    int i = peek(buff);
    int len = (field->hight * field->wide);
    int position_val = -1;
    for(int j = 0; j < len; j++){
        if(field->arr[j] == val){
            position_val = j;
            break;
        }
    }

    int puzzle_row = position_val / field->wide, puzzle_col = position_val % field->wide;
    int e_row = i / field->wide, e_col = i % field->wide;
    if (puzzle_row == e_row){
        if((i + 1 == position_val) || (i - 1 == position_val)){
            return 0;
        }
        else{return 1;}
    }
    else if(puzzle_col == e_col){
        if((i + field->wide == position_val) || (i - field->wide == position_val)){
            return 0;
        }
        else{return 1;}
    }
    else{
        return 1;
    }
}


void swap(Field *field, int i, int j){
    int tmp = field->arr[i];
    field->arr[i] = field->arr[j];
    field->arr[j] = tmp;
}


int generation(Field *field){
    srand(time(NULL));
    field->arr = (int *)malloc(((field->hight)*(field->wide))*sizeof(int));
    if(field->arr == NULL){
        printf("Ошибка выделения памяти\n");
        return -1;
    }
    for(int i = 0; i < ((field->hight) * (field->wide)); i++){
        field->arr[i] = i;
    }
    for(int i = 0; i < ((field->hight) * (field->wide)); i++){
        int j = rand() % (i + 1);
        swap(field, i, j);
    }
    
    int invers = 0, e;
    int len = (field->hight)*(field->wide);
    for(int i  = 0; i <  len; i++){
        if(field->arr[i] != 0){
            for(int j  = 0; j <  len; j++){
                if((field->arr[i] > field->arr[j]) && (field->arr != 0)){
                    invers++;
                }
            }
        }
        else{
            e = (i / (field->hight))+1;
        }
    }

    
    if ((invers + e) % 2 != 0) {
        if (field->arr[0] == 0 || field->arr[1] == 0) {
            swap(field, 2, 3);
        } else {
            swap(field, 0, 1);
        }
    }
    return 0;
}

void print_field(Field *field){
    for(int i = 0; i < ((field->hight)*(field->wide)); i++){
        if (i % field->wide == 0){
            printf("\n");
        }
        printf("%5.0d", field->arr[i]);
    }
    printf("\n");
}

int chek_shift(History *buff, Field *field, int num){
    if(shift(buff, field, num) == 0){
        int position_val;
        for(int i = 0; i < (field->hight * field->wide); i++){
            if(field->arr[i] == num){
                position_val = i;
            }
        }
        int i = peek(buff);
        if(i == -1){
            free_field(field);
            free_history(buff);
            return 1;
        }
        if(push(buff, position_val) == -1){
            free_field(field);
            free_history(buff);
            return 1;
        }
        swap(field, i, position_val);
    }
    else{
        printf("Рядом с этой костяшкой нет свободного места!\n");
    }
    print_field(field);
    return 0;
}
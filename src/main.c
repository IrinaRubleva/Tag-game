#include <locale.h>
#include "input.h"
#include "play_in_15.h"
#include "logic.h"
#include <stdio.h>
#include <stdlib.h>


int main(){
    setlocale(LC_ALL, "en_US.UTF-8");
    Field *field = (Field *)malloc(sizeof(Field));
    if(field == NULL){
        printf("Ошибка выделения памяти.\n");
        return 1;
    }
    printf("Введите высоту поля: ");
    get_int_natur(&(field->hight));
    printf("Введите ширину поля: ");    
    get_int_natur(&(field->wide));

    if (generation(field) == -1){
        free_field(field);
        return 1;
    } 
    print_field(field);
    
    History *buff = create_history();
    if (buff == NULL) {
        free_field(field);
        return 1;
    }
    
    
    for(int i = 0; i < (field->hight * field->wide);i++){
        if(field->arr[i] == 0){
            if(push(buff, i) == -1){
                free_field(field);
                free_history(buff);
                return 1;
            }
        }
    }

    int input, res;
     while (1)
    {
        printf("1 - Подвинуть костяшку на место нуля\n2 - Вернуться назад\n>");
        res = get_int_natur(&input);
        if(res == -1){
            printf("EOF\n");
            free_field(field);
            free_history(buff);
            return 1;
        }
        if(input != 1 && input != 2){
            printf("Ошибка ввода! Попробуйте заново: \n");
            if(res == -1){
                printf("EOF\n");
                free_field(field);
                free_history(buff);
                return 1; 
            }
        }
        if (input == 1){
            int num;
            printf("Введите значение костяшки, которую вы ходите сдвинуть: ");
            res = get_int_natur(&num); 
            if(res == -1){
                printf("EOF\n");
                free_field(field);
                free_history(buff);
                return 1;
            }

            while(0 >= num || num > ((field->hight)*(field->wide)- 1)){
                printf("Такой костяшки не существует! Попробуйте заново: ");
                res = get_int_natur(&num);
                if(res == -1){
                    printf("EOF\n");
                    free_field(field);
                    free_history(buff);
                    return 1;
                }
            }
            chek_shift(buff, field, num);
        }
        if(input == 2){
            if(go_back(buff, field) == -1){
                free_field(field);
                free_history(buff);
                return 1;
            }
            print_field(field);
        }
    }
}
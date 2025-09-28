#include <stdio.h>
#include "input.h"

int get_int_natur(int *val){
    int res;
	char err;
    int try;
    while (1)
    {	
    	res = scanf("%d", &try);
    	if (res == EOF){
    		return -1;
    	}	
    	if(res != 1){
		    printf("Недопустимое значение! Пожалуйста, введите положительное целое значение.\n");
			while(getchar() != '\n');
    				
    	}
    	if (res == 1){
    		scanf("%c", &err);
            if((err == '\n' || err == '\t' || err == ' ')){
            	if(try <= 0){
            		printf("Недопустимое значение! Пожалуйста, введите положительное целое значение.\n");
            	}
            	else{
					*val = try;
					return 0;
				}
            }
			else{
    			printf("Недопустимое значение! Пожалуйста, введите положительное целое значение.\n");
    			scanf("%s", &err);
    		}
        }
	}
}


#ifndef LOGIC_H
#define LOGIC_H

#include "play_in_15.h"

void free_field(Field *field);
int shift(History *buff, Field *field, int val);
void swap(Field *field, int i, int j);
int generation(Field *field);
void print_field(Field *field);
int chek_shift(History *buff, Field *field, int num);

#endif
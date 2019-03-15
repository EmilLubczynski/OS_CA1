#include "lib/my-functions.h"
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#define MAXIMUMBYTES 20480
#define MINIMUMBYTES 2048
#define MINIMUMINDEX 512

int main(){
char *memory = startUp();

int get_number_of_bytes = random_generator(MINIMUMBYTES,MAXIMUMBYTES);
int index;
index = random_generator_2(MINIMUMINDEX,USHRT_MAX);

//starting index location
printf("%d\n", index / 256);
memory = process_bytes(memory, get_number_of_bytes, index);

//dump
free(memory);
return 0;

 }



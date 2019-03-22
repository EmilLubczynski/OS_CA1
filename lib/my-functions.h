#ifndef MYFUNCTIONSH
#define MYFUNCTIONSH
 #include <stdio.h>
 #include <stdio.h>
 #include <limits.h>
 #include <stdlib.h>
 #include <time.h>
 #include <stdbool.h>

 #define MAXIMUMBYTES 20480
 #define MINIMUMBYTES 2048
 #define MINIMUMINDEX 512
 #define PHYSICAL_MEMORY_FILE "./data/physical_memory.txt"
 #define PAGE_TABLE_FILE "./data/page_table.txt"
 #define PAGESIZE 256
 #define MAXIMUMCHAR 127
 #define MINIMUMCHAR 34
 #define MY_USHRT_MAX 65536

 char *startUp();
 int random_generator(int, int);
 int random_generator_2(int, int);
 char *process_bytes();
 void write_physical_memory_file(char *, FILE *);
 void write_page_table_file(char *, FILE *, int, int);
 int compare_input(char*); 
 void search_user_input_in_memory(char*, char*);


#endif

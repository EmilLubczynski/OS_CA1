#include "lib/my-functions.h"

int main(){
char *memory = startUp();

int get_number_of_bytes = random_generator(MINIMUMBYTES,MAXIMUMBYTES);
int index;
index = random_generator_2(MINIMUMINDEX,USHRT_MAX);

//starting index location
printf("%d\n", index / 256);
memory = process_bytes(memory, get_number_of_bytes, index);

FILE *physical_memory_file = fopen(PHYSICAL_MEMORY_FILE, "w");
	if(physical_memory_file == NULL)
	{
	printf("File NAME: %s could not be opened...\n", PHYSICAL_MEMORY_FILE);
	}

FILE *page_table_file = fopen(PAGE_TABLE_FILE, "w");
	if(page_table_file == NULL)
	{
	printf("File NAME: %s could not be opened...\n",PAGE_TABLE_FILE);
	}

write_physical_memory_file(memory,physical_memory_file);
fclose(physical_memory_file);

write_page_table_file(memory,page_table_file,get_number_of_bytes,index); 
fclose(page_table_file);
//dump
free(memory);
return 0;

 }



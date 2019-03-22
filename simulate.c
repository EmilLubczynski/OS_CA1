#include "lib/my-functions.h"

int main(){

//allocate memory
char *memory = startUp();

int get_number_of_bytes = random_generator(MINIMUMBYTES,MAXIMUMBYTES);
int index;
//starting index location
index = random_generator_2(MINIMUMINDEX,USHRT_MAX);
printf("%d\n", index / 256);
//set our random characters up starting at random index
memory = process_bytes(memory, get_number_of_bytes, index);

//open files and check if they are available
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

//write the physical memory address and contents to file
write_physical_memory_file(memory,physical_memory_file);
fclose(physical_memory_file);

//write page table 
write_page_table_file(memory,page_table_file,get_number_of_bytes,index); 
fclose(page_table_file);

char search_memory_input[5];
int done_search = 0;
printf("Please enter a Memory address (ie 0F32),enter STOP to stop searching..\n 0x");
while(done_search !=1)
{
scanf("%4s", search_memory_input);
	if(compare_input(search_memory_input) == 1)
	{
	printf("OK BYE!");
	done_search = 1;
	}
	else
	{
//	search_user_input_in_memory(memory,search_memory_input);
	printf("Eneter another Address.\n 0x");
	}
}

//dump
free(memory);
return 0;

 }



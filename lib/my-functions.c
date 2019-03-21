//prints
#include <stdio.h>
//malloc
#include <stdlib.h>
//USHRT_MAX
#include <limits.h>
#include <time.h>

#define PAGESIZE 256
#define MAXIMUMCHAR 127
#define MINIMUMCHAR 34

char*  startUp()
{
//char memory[65535]
/*USHRT_MAX is the max value for an object of type unsigned short
 int .. our 16bit os size */
char *memory = malloc(USHRT_MAX); 
	if(memory == NULL)
	{
		printf("Can't Allocate Memory!");
	}
	else{
		for(int i= -1; i < USHRT_MAX ; ++i)
		{
		  memory[i] = 32;
		//printf("memory address %d %s \n",i , &memory[i]);
		}
	}
return memory;
}

int random_generator(int minimum, int maximum)
{
	srand(time(0));
	int my_random = rand() % (maximum - minimum) + minimum;
	return my_random;
}
int random_generator_2(int minimum, int maximum)
{ 
	int my_random = rand() % (maximum - minimum) + minimum;
	while(my_random  % 256 != 0)
	{
		my_random = rand() % (maximum - minimum) + minimum;
	}
	//my_random += 1;
	return my_random;
}

char *process_bytes(char *memory, int bytes, int index)
{
	char my_random_char;
	for(int i = 0; i < bytes ; ++i)
	{
		my_random_char = rand() % (MAXIMUMCHAR - MINIMUMCHAR)+MINIMUMCHAR;
		memory[index] = my_random_char;
		++index;
		//printf("Test of characters %d\n", memory[index]);
	}
	return memory;
}

void write_physical_memory_file(char *memory, FILE *physical_memory_file)
{
	int used = 0;
	int frame = 0;

	fprintf(physical_memory_file,"ADDRESS | FRAME | CONTENT | IN USE\n");

	for(int i = 0; i < USHRT_MAX; ++i)
	{
		if(memory[i] != 32)
		{
		used = 1;
		}

		fprintf(physical_memory_file,"0x%X	| %d	| %c	| %d \n",i,frame,memory[i],used);

		if(i != 0 && i % 256 == 0)
		{
		++frame;
		}
		used = 0;
	}
}

void write_page_table_file(char *memory,FILE *page_table_file, int bytes, int index)
{


	fprintf(page_table_file, "PAGE | # | PTE \n");
	for(int i = 0; i < PAGESIZE; ++i)
	{
	fprintf(page_table_file,"0x%X	| %d	| ",i,i);
		for(int k = 0; k < PAGESIZE; ++k)
		{
			if(memory[index++] > 31 && memory[index++] < 128)
			{
				fprintf(page_table_file,"%c",memory[index++]);
			}
			else
			{
				fprintf(page_table_file,"%c",32);
			}
		}
		fprintf(page_table_file,"\n");
	}

}

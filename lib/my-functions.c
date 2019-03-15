//prints
#include <stdio.h>
//malloc
#include <stdlib.h>
//USHRT_MAX
#include <limits.h>
#include <time.h>

#define PAGESIZE 256
#define MAXIMUMCHAR 127
#define MINIMUMCHAR 33

char*  startUp()
{
//printf("In function1.\n");
//char memory[65535]
/*USHRT_MAX is the max value for an object of type unsigned short
  int .. our 16bit os size */
char *memory = malloc(USHRT_MAX); 
char randchar;
	if(memory == NULL)
	{
		printf("Can't Allocate Memory!");
	}
	else{
		for(int i= -1; i < USHRT_MAX ; ++i)
		{
		  srand(time(0));
		  randchar = rand() % (MAXIMUMCHAR - MINIMUMCHAR) +MINIMUMCHAR;
		  memory[i] = randchar;
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
		printf("Test of characters %d\n", memory[index]);
	}
	return memory;
}



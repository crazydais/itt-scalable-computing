//	To compile code in terminal, type...
//	$ gcc hello.c -o hello		("gcc hello.c -> does the compiling"; "-o hello" renames the standard "a.out" filename to "hello")

//	To run the program in terminal, type
//	./hello 

#include <stdio.h>


void workTest ();

int main(int argc, char** argv)
{
	
	workTest();

	return 0;

}	//end main

void workTest ()
{

	char answer;
	int i = 0;	

	printf("\n");

	//printf("hello world!");	

	
	

	//do{

		printf("\ndo some work? y/n  --> ");	
		scanf("%c", &answer);
	
		if(answer == 'y')
		{
			printf("\nReally!!");
			printf("\n");
			//return 0;		
		}
		else if(answer == 'n')
		{
			printf("\nI didn't think so!!");
			printf("\n");
			//return 0;
		}
		else
		{
			for(i = 0; i < 4; i++)
			{
				printf("\nYou need to type 'y' or 'n'");
				printf("\n");
			}
		}
	
	//}while(answer != 'y' || answer != 'n');

	printf("\n\n");

}

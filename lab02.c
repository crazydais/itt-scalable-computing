/*	Part 4:
	--------
To build a program to compute the arithmetic mean and variance (lecture) of an array of integers in C/C++

1. First, we will consider how to allocate space to an array (lecture)
2. We need to set the values of the array once the space has been allocated (lecture).
3. Look at how to design a function in C/C++ (lecture)
4. To design the appropriate function parameter list, we need to look at the objective of the function:
(a) calcAvg 
(b) calcVar
5. Take some time to design the function "prototype"
6. Write the calcAvg and calcVar
*/

//	Week 2, Lab 02

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*	Function Prototypes	
*/

double getAverage(int array[]);

/*	Global variables
*/
const int n = 1000;		//	static global scope
int y = 1000;			//	modifiable global scope

int main(int argc, char** argv)
{

	int arrayOfNumbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	//int r = 10;		//	only visible in main


	double average = getAverage(arrayOfNumbers);

	printf("The average of the array is => %.2f\n", average);

	return 0;
}

double getAverage(int array[])
{
	int i;
	double average = 0;
	long arraySize = (sizeof array / sizeof(array[0]));

	//printf("\nThe total size of the array is => %ld", sizeof array);
	//printf("\nThe total size of each block in the array is => %ld", sizeof(array[5]));

	printf("\narray size => %ld\n", arraySize);

	for(i = 0; i < 10; i++)
	{
		average = average + array[i];
		//printf ("%f\n", average);
	}

	//printf("The sum of all the numbers in the array is => %f\n", average);
	
	average = average / 10;

	return average;
}

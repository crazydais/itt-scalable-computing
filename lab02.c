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

/*  Included libraries
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*	Function Prototypes	
*/

double getAverage(int array[], long count);


/*	Global variables
*/
const int n = 1000;		//	static global scope
int y = 1000;			//	modifiable global scope
int arraySize;

int main(int argc, char** argv)
{

	int i = 0;
	//int r = 10;		//	only visible in main

	printf("\nPlease enter the size of the array => ");
	scanf("%d", &arraySize);

	int userArray[arraySize];
	
	for(i = 0; i < arraySize; i++)
	{
			printf("Please enter a number for array index[%d] => ",i);
			scanf("%d", &userArray[i]);
	}

	//printf("\nThe total size of the array is => %ld", sizeof arrayOfNumbers);
	//printf("\nThe total size of each block in the array is => %ld", sizeof arrayOfNumbers[0]);
	//long arrayCount = (sizeof arrayOfNumbers / sizeof arrayOfNumbers[0]);
	//printf("\nArray Count => %ld", arrayCount);
	
	double average = getAverage(userArray, arraySize);

	printf("\nThe average of the array is => %.2f\n", average);

	return 0;
}


double getAverage(int array[], long count)
{
	int i;
	double average = 0;

	for(i = 0; i < count; i++)
	{
		average = average + array[i];
		//printf ("%f\n", average);
	}

	//printf("\nAverage => %f\n", average);
	
	average = average / count;

	return average;
}

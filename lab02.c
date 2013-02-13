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


/*	Global variables
*/
const int n = 1000;		//	static global scope
int y = 1000;			//	modifiable global scope
long arraySize;

/*	Function Prototypes	
*/

void populateArray(int *array, long count);
double getAverage(int *array, long count);
double getVariance(int *array, long count, double average);

//  Main...

int main(int argc, char** argv)
{
	printf("Please enter the array size => ");
	scanf("%ld", &arraySize);

	int userArray[arraySize];
	
	populateArray (userArray, arraySize);

	double average = getAverage(userArray, arraySize);

	double variance = getVariance(userArray, arraySize, average);

	printf("\nThe average of the array is => %.2f\n", average);

	printf("\nThe variance of the array is => %.2f\n", variance);

	return 0;
}

//	  Functions...

void populateArray (int *array, long count)
{
	int i;
	
	for(i = 0; i < count; i++)
	{
		array[i] = rand() % 100;
	}

}

double getAverage(int *array, long count)
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

double getVariance(int *array, long count, double average)
{
	int i;
	double variance;

	for(i = 0; i < count; i++)
	{

	}
	
	
	return variance;
}

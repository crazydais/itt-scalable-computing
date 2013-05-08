#include <omp.h>

#include "vectoradd.h"

//Fills two arrays with pseudo-random numbers.
//This uses OMP to parallelize this job on the CPU.
//In visual studio, the compiler also needs a "/openmp" switch to enable OMP. 
//.. you can set this in the project properties under the C++/Language section.

void fillvector(unsigned int *v1, unsigned int *v2)
{

	#pragma omp parallel for
	for(int i=0;i < VECTORSIZE;i++)
	{
		v1[i] = (rand() % 9) + 1;
		v2[i] = (rand() % 9) + 1;
	}

}
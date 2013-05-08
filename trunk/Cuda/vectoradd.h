#ifndef VECTORADD_H
#define	VECTORADD_H

#include "cuda_runtime.h"
#include <stdio.h>
#include <stdlib.h>


#define VECTORSIZE 100000000 


//Function prototypes:
void fillvector(unsigned int*, unsigned int*);
void addVectors(unsigned int*, unsigned int*, unsigned int*);
__global__ void gpu_addVectors(unsigned int*, unsigned int*, unsigned int*);



#endif
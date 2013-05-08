#include "vectoradd.h"
#include <time.h>


void main(int argc, char *argv[])
{
	//our program takes one input parameter.
	// vectoradd.exe 0 = do a cpu vector addition
	// vectoradd.exe 1 = do a gpu vector addition	
	// If you are debugging in visual studio, make sure you include your parameter - see project properties/debugging/CommandArguments.

	// C counts the program name itself as the first parameter so we need to check there are 2 parameters.
	if(argc != 2)
	{
		// No parameter supplied, end the program
		printf("\n\nUsage : 0 = cpu addition , 1 = gpu addition\n\n");
		return;
	}

	// Convert the parameter string to an integer using C atoi() function.
	int additionType = atoi(argv[1]);

	//make sure additionType has a default value of 0 or 1
	if(additionType != 0 && additionType != 1)
		additionType = 0;
		

	// clock_t is a C stopwatch structure that that helps us to time a process.
	clock_t begin,end;

	// Get the number of bytes required by each array = number of elements multiplied by the byte-size of each element
	unsigned int numbytes = VECTORSIZE * sizeof(int);
	
	// These arrays are far too big to declare in local stack memory, so we allocate them dynamically in the heap memory (i.e. DRAM).
	// Local arrays are usually stored in stack memory. Declaring array as "int a[VECTORSIZE]" would use up our stack memory and we would get a "stack overflow" error.
	// "malloc" allows us to allocate memory on the heap (i.e. dynamic RAM or DRAM). It returns a void pointer to the first byte which we cast to an "unsigned int" pointer.
	unsigned int *a = (unsigned int*)malloc(numbytes);	
	unsigned int *b = (unsigned int*)malloc(numbytes);			
	unsigned int *r = (unsigned int*)malloc(numbytes);	
	

	// Call a function to fill the vectors a and b with pseudo-random values
	fillvector(a,b);
		

	// Add vectors. 
	// We want to add vectors a and b and store the results of each element pair in vector r.
	if(additionType == 0)
	{
		//CPU addition
		printf("\nPerforming CPU vector addition\n");
		begin = clock();	// start timer
		addVectors(a,b,r);
		end = clock();		// stop timer
	}
	else
	{
		//GPU add vectors
		printf("\nPerforming GPU vector addition\n");

		// Allocate memory on the gpu for vectors a , b and r.
		unsigned int *ga, *gb, *gr;
		cudaMalloc((void**)&ga, numbytes);
		cudaMalloc((void**)&gb, numbytes);
		cudaMalloc((void**)&gr, numbytes);

		// Copy vectors a and b over to the GPU
		cudaMemcpy(ga, a, numbytes, cudaMemcpyHostToDevice);
		cudaMemcpy(gb, b, numbytes, cudaMemcpyHostToDevice);

		begin = clock(); // Start the timer
		gpu_addVectors<<< 1024,1024  >>>(ga,gb,gr); // Call the kernel with a grid of 1048 blocks, each with 1024 threads
		end = clock(); // Stop the timer

		// Copy the results vector gr from the device back to the host
		cudaMemcpy(r, gr, numbytes, cudaMemcpyDeviceToHost);

		// We should free up the memory on the gpu when we are finished with it by using cudaFree.
		cudaFree(ga);
		cudaFree(gb);
		cudaFree(gr);

		//Rest the device to flush profile data (helps the Visual Profiler tool)
		cudaDeviceReset();
	}
		
	printf("\nTime taken = %f\n",(double)(end - begin)/CLOCKS_PER_SEC); // output timer results


	// Output the results vector r
	printf("\n\nFinished!  Outputting some results...");
	for(int i=0;i<5;i++)
	{
		printf("\n%d \t %d,%d = %d",i,a[i],b[i],r[i]);
	}
	printf("\n...");
	for(int i=VECTORSIZE-5;i < VECTORSIZE;i++)
	{
		printf("\n%d \t %d,%d = %d",i,a[i],b[i],r[i]);
	}

	// We should always free up dynamically allocated memory when we are finished with it by using free()
	free(a);
	free(b);
	free(r);

}



// CPU add 2 vectors v1 and v2, place the results in "result" vector
void addVectors(unsigned int *v1, unsigned int *v2, unsigned int *result)
{
	for(unsigned int i=0;i < VECTORSIZE;i++)
	{
		result[i] = v1[i] + v2[i];
	}

}



// GPU kernel to add 2 vectors v1 and v2, and place the results in "result" vector
__global__ void gpu_addVectors(unsigned int *v1, unsigned int *v2, unsigned int *result)
{
	// Calculate the unique thread index
	unsigned int tid = threadIdx.x + blockIdx.x * blockDim.x;

	
	// Ordinarily we could use the following line of code to do the work:  
	// result[tid] = v1[tid] + v2[tid];   // use the unique thread id to map this thread to a particular vector element to do its work

	// However if the number of threads we launch is less than the VECTORSIZE, only some of the vector elements will be processed!	
	// In our case we have only launched a grid of 1024 blocks of 1024 threads, so only approx 1m elements will be processed. 
	// nb - CUDA imposes a block size limit of 1024 threads , and a grid size of 65536 blocks.

	// This while loop helps us cope with vectors that are much bigger than 1m elements...
	// Each thread will perform additions on several unique elements 
	// One in the range 0 - 1m
	// The next in the range 1m - 2m
	// The next in the range 2m - 3m
	// ... and so on, until the VECTORSIZE is reached.
	while(tid < VECTORSIZE) { 

		result[tid] = v1[tid] + v2[tid]; 	// use the unique thread id to map this thread to a particular memory address to do its work

		tid += blockDim.x * gridDim.x;	// increase the thread id by the total number of threads (1024 x 1024).
	}


	// If comment out the while loop and just leave in the "result[tid] = v1[tid] + v2[tid];" , the output will show you that only
	// the first 1m elements of our vectors were processed. The later elements of the results array will show random (i.e. unitialized) values.
	// nb- Just because you allocate memory in C for arrays, it doesn't mean that it will initialize the elements to any particular value such as zero !

	// When you see unexpected large negative or exponential values in C variables, it usually means you are either reading unitialized values or your
	// are reading outsize of your array bounds!
}
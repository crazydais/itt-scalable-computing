#include <stdio.h>
#include <cuda_runtime.h>

#include "cudalab1.h"

int main(int argc, char **argv) 
{
	//CUDA lab 1 
	// Query the PC's NVIDIA GPU device and display some of it's characteristics.
	// Launch a simple kernel on the GPU.
	//**********************************************************************************

	
	printf("CUDA Lab 1\n\n");

	
	//Query the device properties. 
	//CUDA provides a cudaDeviceProp structure which stores device properties.
	//We declare an in instance of the structure and pass it's address along with the GPU number (default 0) into the cudaGetDeviceProperties function.
	//The function populates the structure properties with info.
	cudaDeviceProp dprops;
	cudaGetDeviceProperties(&dprops,0);
		
	
	//Output device name and number of MPs 
	printf("Found device %s, with %d multiprocessors.\n\n", 
		dprops.name, 
		dprops.multiProcessorCount );

	//There are many properties available to examine!
	// e.g.    	dprops.totalGlobalMem  ,  	dprops.maxThreadsPerBlock   etc etc

		
	//Define an array in the computers RAM
	int pcdata[1024];

	//Work out the number of elements in array and assign a number to each element
	//Useful C tip : Number of elements in array = total number of bytes in the array divided by number bytes per array element !
	int pcdataElements = sizeof(pcdata) / sizeof(pcdata[0]); 
	for(int i=0;i < pcdataElements; i++)
	{
		pcdata[i] = i;

		if(i<5)
			printf("%d ", pcdata[i]);
	}


	//Copy the array onto the GPU
	//First, define a pointer which will be the address of the memory alocated on the gpu
	int *gpudata;	

	//Allocate memory on the gpu using cudaMalloc
	//cudaMalloc expects a pointer and the number of bytes to allocate
	cudaMalloc((void**)&gpudata, sizeof(pcdata));

	//Copy data onto the gpu at the appropriate address
	cudaMemcpy(gpudata,pcdata,sizeof(pcdata),cudaMemcpyHostToDevice);
	
	
	//Invoke the kernel.  It consists of a grid of 1 block which contains 1024 threads.
	SimpleKernel<<<1,1024>>>(gpudata);

	
	//Copy the results array back to the computers RAM
	cudaMemcpy(pcdata,gpudata,sizeof(pcdata),cudaMemcpyDeviceToHost);

	
	//Free up the device memory after we are finished with it.
	cudaFree(gpudata);

	printf("\n");
	for(int i=0;i < 5; i++)
	{
		if(i<5)
			printf("%d ", pcdata[i]);
	}


}


//This simple kernel multiplies each element of the array by 10.
//In C we use pointers to pass array references into functions (see lecture 2).
__global__ void SimpleKernel(int *gpudata)
{
	//Notice how we don't now have a loop to process the array!

	//Get the unique thread id. threadIdx.x contains each thread's unique Id within the block.
	int tid = threadIdx.x;

	//Map the thread id to the array element for this thread and do our processing
	gpudata[tid] = gpudata[tid] * 10;
}
#include <pthread.h>
#include <stdio.h>

#define NUM_THREADS	10

//int arraySize = 50;
long array[50];

void *PrintHello(void *threadid);

void *PrintHello(void *threadid)
{
		//long chunk = arraySize / NUM_THREADS;
		long chunk = sizeof(array) / sizeof(array[0]) / NUM_THREADS;		//	This gets the size of the array by dividing it's total size by each array element size, and then dividing that by the number of threads...
		//printf("\nChunk = %ld", chunk);
		
		long tid = (long)threadid;
		//printf("\nTid = %d", (int)threadid);

		long start = chunk * tid;
		//printf("\nStart = %d", start);

		long stop = start + chunk;
		//printf("\nStop = %d", stop);

			for(int i = start; i < stop; i++)
			{
				array[i] = (long)tid;
				printf("\nThread id_%ld at index_%d", array[i], i);
			}	

			   printf("\n");			
}


int main (int argc, char *argv[])
{
   

   pthread_t threads[NUM_THREADS];

   for(long t = 0; t < NUM_THREADS; t++)
   {
      int rc = pthread_create(&threads[t], NULL, PrintHello, (void *)t);
   }

   /* Last thing that main() should do */

   pthread_exit(NULL);

   //	Why doesn't this execute????
   printf("\n ----------------------");
   printf("\n ----------------------");
   printf("\n ----------------------");
   printf("\n ----------------------");
   printf("\n ----------------------");

}
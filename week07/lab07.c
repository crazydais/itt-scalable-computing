#include <pthread.h>
#include <stdio.h>

#define NUM_THREADS	10

int arraySize = 50;
long array[50];

void *PrintHello(void *threadid);

void *PrintHello(void *threadid)
{
		int chunk = arraySize / NUM_THREADS;
		
		int tid = (int)threadid;
		//printf("\nTid = %d", (int)threadid);

		int start = chunk * tid;
		//printf("\nStart = %d", start);

		int stop = start + chunk;
		//printf("\nStop = %d", stop);


		int i;
			for(i = start; i < stop; i++)
			{
				array[i] = (long)tid;
				printf("\nThe thread id_%ld at index_%d", array[i], i);
			}	

			   printf("\n");			
}


int main (int argc, char *argv[])
{
   

   pthread_t threads[NUM_THREADS];

   for(int t = 0; t < NUM_THREADS; t++)
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
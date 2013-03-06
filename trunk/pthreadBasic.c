#include <pthread.h>
#include <stdio.h>
#define NUM_THREADS     5

void *PrintHello(void *threadid);

void *PrintHello(void *threadid)
{
	printf("\nHello World! It's me, thread #%d!",(int)threadid);
}

int main (int argc, char *argv[])
{
   pthread_t threads[NUM_THREADS];

   for(int t = 0; t < NUM_THREADS; t++){
      int rc = pthread_create(&threads[t], NULL, PrintHello, (void *)t);
   }

   /* Last thing that main() should do */
   pthread_exit(NULL);
}


//	gcc -std=c99 pthreadBasic.c -o pthreadBasic -lpthread 


//	void * => can  be passed to any data type.
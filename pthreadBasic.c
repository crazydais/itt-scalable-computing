#include <pthread.h>
#include <stdio.h>

#define NUM_THREADS     5

void *PrintHello(void *threadid);

void *PrintHello(void *threadid)
{
	int i;

		printf("\nHello World! It's me, thread #%ld!",(long)threadid);	
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
}


//	gcc -std=c99 pthreadBasic.c -o pthreadBasic -lpthread 


//	void * => can  be passed to any data type.

/*
pthread_create (thread,attr,start_routine,arg)

pthread_create arguments...

thread:		An opaque, unique identifier for the new thread returned by the subroutine.
attr: 		An opaque attribute object that may be used to set thread attributes. You can specify a thread attributes object, or NULL for the default values.
start_routine: the C routine that the thread will execute once it is created.
arg: 		A single argument that may be passed to start_routine. It must be passed by reference as a pointer cast of type void. NULL may be used if no argument is to be passed.

The maximum number of threads that may be created by a process is implementation dependent. Programs that attempt to exceed the limit can fail or produce wrong results.

*/
#include <omp.h>
#include <stdio.h>

int buffer[100];

int main ()  
{

  int nthreads, tid;

    /* Fork a team of threads with each thread having a private tid variable */
    #pragma omp parallel num_threads(3) private(tid)
      {

      /* Obtain and print thread id */
      tid = omp_get_thread_num();
      printf("Hello World from thread = %d\n", tid);

      /* Only master thread does this */
      if (tid == 0) 
        {
          nthreads = omp_get_num_threads();
          printf("Number of threads = %d\n", nthreads);
        }

      }  /* All threads join master thread and terminate */


      //#pragma omp parallel for schedule(runtime)
      #pragma omp for schedule(runtime) 
      for(int i = 0; i < 100; i++)
      {
        buffer[i] = omp_get_thread_num();
      }

    #pragma omp barrier
        for(int i = 0; i < 100; i++)
        {
          printf("data --> %d, %d\n", buffer[i], i);
        }

  return 0;
}

//  $   gcc -std=c99 lab08v0.c -o lab8v0 -fopenmp

//  $   export OMP_SCHEDULE="guided,2"  ||  export OMP_SCHEDULE="dynamic"

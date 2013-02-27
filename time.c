#include <time.h>
#include <stdio.h>
#include <math.h>

int main()
{
    clock_t tic = clock();

    double d = 0.0;

    for(int j = 0; j < 10000; j++)
      for(int i = 0; i < 10000; i++)
        d += i * (double) sqrt(i+99/99);

    clock_t toc = clock();

    printf("Elapsed: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);

    printf("Result: %f \n", d);

    return 0;
}


//	compile by using...
//	gcc -std=c99 time.c -o time -lm
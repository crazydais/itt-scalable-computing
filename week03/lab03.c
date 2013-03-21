#include <stdio.h>


float scores[4];

void getScores(float* scores);
void printScores(float* scores);

int main(int argc, char* argv[])
{
      
      printf("Enter four floats: \n");
      
      getScores(scores);


      printf("\nThe scores in reverse order are: \n");

      printScores(scores);

      printf("\n\n");
      
      return 0;
}


void getScores(float* scores)
{
      int i;

      for (i = 0; i < 4; i++)
      {
            scanf("\n%f", &scores[i]);
      }
}

void printScores(float* scores)
{
      int i;

      for(i = 3; i >= 0; i--)
      {
            printf("\nScore_[%i] - %f", (i+1), scores[i]);
      }
}
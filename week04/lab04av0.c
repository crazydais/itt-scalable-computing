#include <stdio.h>
#include <stdlib.h>   //  for 'malloc'


int main(int argc, char* argv[])
{

    //  Create two local int variable, i and n 
    int i, n; 
    
    //  Create a pointer(*) called 'buffer' which is of a char type.  The pointer will point to a location in memory.  The size of the memory allocation is determined by the data type, in this case a char, and how many chars.  In this sense, the memory allocated can be thought of as an array of characters. 
    char *buffer;

    //  Prints out this message to the terminal
    printf ("How long do you want the string? ");
    //  Scan in a number, entered by a user in the terminal, and store the result in 'i'
    scanf("%d", &i);

    //  The buffer pointer is equal to the memory allocation of size set by the user +1, and is cast a char*.  The cast may not be necessary, and could just be used for convention.
    //  We need to be able to dynamically set the size of the buffer because we don't know how big the sting is going to be.
    //  The extra +1 is for the last character to be '\0', ie, zero escaped. 
    buffer = (char*) malloc (i+1);

    //  Check to make sure the buffer is not empty.
    //  If the buffer is empty, then exit the program
    if (buffer == NULL) 
    //  The exit() terminates the program much like the return statement in the main function. It return control to the operating system. It closes open files, flushes output buffers, and calls destructors before control is returned to the operating system. The parameter passed to the function are exit status values which communicate to the operating system the program terminated prematurely or everything happened as expected. For example exit(0) (same as return 0) means the program terminated normally. exit(1) (same as return 1) means the program terminated because of some error ( it could not open a file, allocate memory, etc. ).
    exit (1);

    //  This FOR loop adds a random character to each character memory space of the allocated memory
    for (n=0; n<i; n++) 
    {
      //  This generates a random number, from 1 - 26, a uses the character 'a' as a base reference character.  The random int generated is added to the character 'a', and a new character is generated, which is a letter int positions from 'a'.  (ie, if the random int generated is 2, then the 2 + 'a' = 'c') 
      buffer[n] = rand() % 26 +'a';
    }
   
    //  This zero escapes the last char in the allocated memory block, so the compiler knows it has reached the end of an string
    buffer[i]='\0';

    //  This prints the entire string in the buffer
    printf ("Random string: %s\n",buffer);

    //  This line shows us that we can add an int with a char.  The result is a char.  The char in the equation sets the base point
    //int t = 2;
    //char b = 'b';
    //printf("The new character by adding int %d with char %c => %c\n", t, b, (t+b));  // (ie, the result will be 'd')

    //  This free's the memory which was allocated using malloc
    free (buffer);

} //  The program ends


//  gcc -std=c99 lab04av0.c -o lab4v0 
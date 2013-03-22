/*
*		This program illustrates pointers in C
*
*		**		NOTE	**
*		To type '#' in Ubuntu, while using a virtual machine, use the ALT key on the right side
*		of the keyboard, not the left side as you would on a Mac.
*
*		http://www.cprogramming.com/tutorial/c/lesson6.html
*
*/		

#include <stdio.h>
#include <stdlib.h>

//	Create a function prototype, which does not return a value (void), and takes only one argument, an int pointer (int *)
//	This function will change the value of x, which was declared in the main function. 
void changeValueOfX (int *);

int main()
{

	int x = 10;
	int *p;
	p = &x;

	printf("\nthe value of x is: %d", x);

	changeValueOfX(p);

	printf("\nthe value of x is: %d", x);

	changeValueOfX(&x);

	//	Print out the value contained in defererenced memory address
	printf("\nthe value of x is: %d", *p);
	printf("\nthe value of x is: %d", *(&x));

	printf("\n");

	return 0;
}

void changeValueOfX (int *z)
{
	//	we have received an int pointer as an argument, and I have named it 'z', just to show that it does not have to be called 'x'
	//	we have passed in the memory address of the int variable called 'x' which is important. 
	//	by 'dereferencing' the pointer, we can now change the value stored in the memory address of x.  We can dereference a pointer by using adding the '*' symbol in front of the pointer variable name, in this case 'z'


	*z = 15;
}
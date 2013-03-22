#include <stdio.h>
#include <stdlib.h>   //  for 'malloc'
#include <stdbool.h>

//#define MAX_SENTENCE_LENGTH 20;

int MAX_SENTENCE_LENGTH = 20;

int main(int argc, char* argv[])
{
	char userText[21];		//	There is 21 places so the user can input a string 20 char long, and the 21st is '\0', indicating the end of a string
	char escapeCharacter = '\0';
	char space = ' ';
	int i;
	int stringLength;

	//	This populates the entire userText with '\0' characters, so when a string is written to userText, the very last character will definitely be a '\0'.
	//	We need this for later when we want to calculate the lenght of the entered string. 
	for(i = 0; i < 21; i++)
	{
		userText[i] = '\0';
	}


	printf("\nPlease enter some text, and the progam will check for a palindrome\nThe max length of the sentence is 20 character\n>");
	//scanf("%s", userText);		
	scanf("%[^\n]", userText);		//	This means "read anything up until a newline" as a string. 


	printf("\nYour string was: \"%s\"", userText);


	//	This checks for the first instance of an end of string, '\0'. 
	//	When it's found, stringLenght is set to the index of where '\o' was found and the FOR loop exits.
	for(i = 0; i < 20; i++)
	{
		if(userText[i] == escapeCharacter)
		{
			stringLength = i;
			i = 20;
		}
	}
	printf("\nThe lenght of the string was: %d", stringLength);
	printf("\n");

	//	This FOR loop scans the string for any spaces and removes them
	for(i = 0; i <= stringLength; i++)
	{
		if(userText[i] == space)
		{
			int j, k = i;

			for(j = i+1; j < stringLength; j++)
			{
				userText[k] = userText[j];
				k++;
			}

			userText[stringLength - 1] = '\0';
		}
	}
	printf("\nYour string, without spaces is:\"%s\"", userText);
	
	//	This checks again for the length of the string, now that all the spaces have been removed...
	for(i = 0; i < 20; i++)
	{
		if(userText[i] == escapeCharacter)
		{
			stringLength = i;
			i = 20;
		}
	}
	printf("\nThe lenght of the string is now: %d", stringLength);
	printf("\n");


		//	This checks for a palindrome by comparing each element in the array with its polar opposite.
		//	(eg, check the very first element against the very last element)
		//	If all the polar opposite element are equal to each other, then the string is a palindrome...
		bool isPalindrome;

		for(i = 0; i < stringLength; i++)
		{
			if(userText[i] == userText[(stringLength - 1) - i])
			{
				isPalindrome = true;
			}
			else
			{
				isPalindrome = false;
			}
		}

		if(isPalindrome)
		{
			printf("\nHorray!!!  That is a palindrome");
			printf("\n");
		}
		else
		{
			printf("\nNope!!!! That is not a palindrome");
			printf("\n");
		}

    return 0;

} //  The program ends

//	To compile the program, use this terminal command...
//	$	gcc -std=c99 lab04bv1.c -o lab4bv1
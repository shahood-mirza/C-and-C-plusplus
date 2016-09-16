/*
String and Character Manipulation
By: Shahood Mirza

Description:
This program manipulates strings and characters in several different ways. Using the menu, you
have the option to: eliminate spaces, convert strings to floats, circular concatenation, new
line character elimination (from fgets) and character tally

*/

#include "Main.h"

///////////////////////////////////////////////////////////////////////////
///////////////////////SPACE ELIMINATION FUNCTION//////////////////////////
void SpaceElim (char string[ArraySize])
{
	int i, j=0;

	printf("Please Enter a String With Spaces: ");
	fgets(string, ArraySize, stdin);

	for(i=0; i<ArraySize; i++)
	{
		if(string[i] != ' ')
		{
			string[j] = string[i];	//replace space char with next char in array
			j++;
		}
	}
	
	printf("\nSpaces Eliminated!\n");
	printf("%s", string);

	printf("\nPress Any Key to Continue...");
	getch();
}

///////////////////////////////////////////////////////////////////////////
///////////////////////STRING TO FLOAT FUNCTION////////////////////////////
void StringToFloat (char string[ArraySize])
{
	int i, decPos = -1, badInput = TRUE, decFound = FALSE;
	float strFlt;

	while(badInput)
	{
		badInput = FALSE;	//start by assuming a good input
		printf("Please Enter a String (In Currency Format): $");
		fgets(string, ArraySize, stdin);

		for(i=0; i<(strlen(string)-1); i++)	//do not count new line char from fgets
		{
			if(string[i] == '.' && !decFound)
			{
				decPos = i;
				decFound = TRUE;	//in case of multiple decimal places
			}
			if(!isdigit((unsigned char)string[i]) && (decPos != i)) //make sure to skip decimal point
			{
				system("cls");
				printf("Please Enter Only Currency Values!\n");
				i = strlen(string);
				badInput = TRUE;	//the input is bad if a non-digit is detected
			}
		}
	}

	strFlt = atof(string);

	printf("\nThe string entered is now a float: $%.2f\n", strFlt);

	printf("\nPress Any Key to Continue...");
	getch();
}

///////////////////////////////////////////////////////////////////////////
///////////////////STRING CONCATENATION FUNCTION///////////////////////////
void StringConcat (char string1[ArraySize], char string2[ArraySize])
{
	int i, space, rmn, str1len, str2len;

	printf("Please Enter a String: ");
	gets(string2);	//use gets instead of fgets so there is newline character appended

	str1len = strlen(string1);
	str2len = strlen(string2);

	space = ArraySize - str1len;

	if(space > str2len)	//append if the buffer has more space than the size of the input
		rmn = 0;
	else
		rmn = str2len - space;	//prefix only if the buffer has less space

	for(i=0; i<space; i++)
	{
		string1[str1len] = string2[i];
		str1len++;
	}

	for(i=0; i<rmn; i++)
	{
		string1[i] = string2[str2len-rmn];
		str2len++;
	}

	//the string terminator is overwritten during concatenation
	//it is important to add it to the correct spot in the array
	if((str1len+str2len) > ArraySize)
		string1[ArraySize] = '\0';
	else
		string1[str1len+str2len] = '\0';

	printf("\nStrings Concatenated!\n");
	printf("%s", string1);

	printf("\n\nPress Any Key to Continue...");
	getch();
}

///////////////////////////////////////////////////////////////////////////
/////////////////////NEW LINE ELIMINATION FUNCTION/////////////////////////
void NewLineElim (char string[ArraySize])
{
	int i;

	printf("Please Enter a String: ");
	fgets(string, ArraySize, stdin);
	
	printf("\nBefore: \n");
	printf("%s", string);
	printf("%s", string);

	for(i=0; i<ArraySize; i++)
	{
		if(string[i] == '\n')	//replace trailing newline with string terminator
			string[i] = '\0';
	}

	printf("\nAfter: \n");
	printf("%s", string);
	printf("%s", string);

	printf("\n\nPress Any Key to Continue...");
	getch();
}

///////////////////////////////////////////////////////////////////////////
///////////////////////CHARACTER TALLY FUNCTION////////////////////////////
void CharTally (char string[ArraySize])
{
	int i, tally[5];

	printf("Please Enter a String: ");
	fgets(string, ArraySize, stdin);

	for (i=0; i<5; i++)
	{
		tally[i] = 0;	//initalize tally to zero
	}

	for(i=0; i<strlen(string); i++)
	{
		if(islower((unsigned char)string[i]))	//strings are by default signed chars
			tally[0]++;							//the comparison functions only use unsigned chars
		else if(isupper((unsigned char)string[i]))
			tally[1]++;
		else if(isdigit((unsigned char)string[i]))
			tally[2]++;
		else if(ispunct((unsigned char)string[i]))
			tally[3]++;
		else if(isspace((unsigned char)string[i]))
			tally[4]++;
	}

	printf("\nNumber of Lower-Case Characters: %d\n", tally[0]);
	printf("Number of Upper-Case Characters: %d\n", tally[1]);
	printf("Number of Digits: %d\n", tally[2]);
	printf("Number of Punctuation Marks: %d\n", tally[3]);
	printf("Number of Spaces: %d\n", tally[4]-1);	//trailing "new line" is counted as space and should not be tallied

	printf("\nPress Any Key to Continue...");
	getch();
}

///////////////////////////////////////////////////////////////////////////
/////////////////MAIN FUNCTION - PROGRAM STARTS HERE///////////////////////
int main (void)
{
	char choice = '0';
	char string[ArraySize], string2[ArraySize];
	int i;

	string[0] = '\0';	//make string initially blank

	while(choice != '6')
	{
		system("cls");

		printf("Select an Option (1-6):\n");
		printf("1. Eliminate Spaces From String\n");
		printf("2. Convert String to Float\n");
		printf("3. String Catenation\n");
		printf("4. New-Line Elimination\n");
		printf("5. Tally Character Occurrences\n");
		printf("6. Exit\n");

		choice = getch();

		system("cls");

		switch(choice)
		{
			case '1':
			{
				SpaceElim(string);
				break;
			}
			case '2':
			{
				StringToFloat(string);
				break;
			}
			case '3':
			{
				StringConcat(string, string2);
				break;
			}
			case '4':
			{
				NewLineElim(string);
				break;
			}
			case '5':
			{
				CharTally(string);
				break;
			}
			case '6':
			{
				break;
			}
			default:
			{
				printf("Invalid Entry. Press Any Key to Continue...");
				getch();
			}
		}
	}

	return 0;
}
/***********************************************************************
* Program:
*    Test 4, Count Letters & Digits
*    Brother Falin, CS124
* Author:
*    Joseph Walker
* Summary:
*    This program will count the amount of digits, letters, symbols,
*	 and spaces in a given text from a user.
*
*    Estimated:  1.0 hrs
*    Actual:     0.0 hrs
*      Working with the pointers
************************************************************************/
#include <cstdlib>
#include <iomanip> 
#include <iostream>
#include <string>
#include <cctype>
using namespace std;
#define MAX 256
int textCount(int argc, char **argv, int digitCount[],
int letterCount[], int symbolCount[], int spaceCount[]);
int textCountInput(char input[], int digitCount[], int letterCount[],
int symbolCount[], int spaceCount[]);

/**********************************************************************
 * main
 * This function will collect and store the user text and display
 * the letter, digit, space, and symbol count of the text.
 ***********************************************************************/
int main(int argc, char **argv)
{
	cout.setf(ios::showpoint);
	cout.setf(ios::fixed);
	cout.precision(1);
	
	char input[MAX];
	int digitCount[1] = {0};
	int letterCount[1] = {0};
	int symbolCount[1] = {0};
	int spaceCount[1] = {0};
	
	if (argc == 1)
	{
		cout << "Please enter some text: ";
		cin.getline(input, MAX);
		textCountInput(input, digitCount, letterCount, symbolCount, spaceCount);
	}
	else
	{
		textCount(argc, argv, digitCount, letterCount, symbolCount, spaceCount);
	}
	
	cout << setw(10) << left << "\tLetters:" << letterCount[0] << endl;
	cout << setw(10) << left << "\tDigits:" << digitCount[0] << endl;
	cout << setw(10) << left << "\tSymbols:" << symbolCount[0] << endl;
	cout << setw(10) << left << "\tSpaces:" << spaceCount[0] << endl;
	
}

/********************************************************************
 * text count
 * Will count the number of digits, letters, symbols, and spaces in
 * the text given as an arg command.
 ***********************************************************************/
int textCount(int argc, char **argv, int digitCount[],
int letterCount[], int symbolCount[], int spaceCount[])
{
	int count = 0;
	for (int i = 1; i < argc; i++)
	{
		for (int j = 0; argv[i][j]; j++)
		{
			if (isdigit(argv[i][j]))
			{
				digitCount[0]++;
			}
			else if (isalpha(argv[i][j]))
			{
				letterCount[0]++;
			}
			else if (ispunct(argv[i][j]))
			{
				symbolCount[0]++;
			}
		}
	}
	spaceCount[0] = argc - 2;
	return count;
}

/********************************************************************
 * text count input
 * Will count the number of digits, letters, symbols, and spaces of
 * the text given by the user after the program starts.
 ***********************************************************************/
int textCountInput(char input[], int digitCount[],
int letterCount[], int symbolCount[], int spaceCount[])
{
	int count = 0;
		for (int i = 0; input[i]; i++)
		{
			if (isdigit(input[i]))
			{
				digitCount[0]++;
			}
			else if (isalpha(input[i]))
			{
				letterCount[0]++;
			}
			else if (ispunct(input[i]))
			{
				symbolCount[0]++;
			}
			else if (isspace(input[i]))
			{
				spaceCount[0]++;
			}
		}
		return count;
}

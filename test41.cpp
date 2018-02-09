/***********************************************************************
* Program:
*    Test 4.1, Practice Test 1
*    Brother Falin, CS124
* Author:
*    Joseph Walker
* Summary:
*    
*
*    Estimated:  0.0 hrs
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/
#include <cstdlib> 
#include <iostream>
#include <string>
#include <cctype>
using namespace std;
#define MAX 50
int countDigits(int argc, char *argv[]);
int countInputDigits(char input[]);

/**********************************************************************
 * main
 * 
 * 
 * 
 ***********************************************************************/
int main(int argc, char *argv[])
{
	cout.setf(ios::showpoint);
	cout.setf(ios::fixed);
	cout.precision(1);
	
	char input[MAX];
	int count;
	
	if (argc == 1)
	{
		cout << "Please enter a word to check: ";
		cin.getline(input, MAX);
		count = countInputDigits(input);
	}
	else
	{
		count = countDigits(argc, argv);
	}
	
	if (count == 1)
	{
		 cout << "There is 1 digit" << endl;
	}
	else if (count > 1)
	{
		cout << "There are " << count << " digits" << endl;
	}
	else
	{
		cout << "There are no digits" << endl;
	}
	
	
}

/********************************************************************
 * convert feet to meters
 * Will convert and return the value of feet to meters.
 ***********************************************************************/
int countDigits(int argc, char *argv[])
{
	int count = 0;
	for (int i = 1; i < argc; i++)
	{
		for (int j = 0; argv[i][j]; j++)
		{
			if (isdigit(argv[i][j]))
			{
				count++;
			}
		}
	}
	return count;
}

int countInputDigits(char input[])
{
	int count = 0;
		for (int i = 0; input[i]; i++)
		{
			if (isdigit(input[i]))
			{
				count++;
			}
		}
		return count;
}

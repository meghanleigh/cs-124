/***********************************************************************
* Program:
*    Assignment 32, Strings
*    Brother Falin, CS124
* Author:
*    Joseph Walker
* Summary:
*    This program will prompt the user for a letter and words. It will
*    then evaluate and count how many times the given letter appears in
*    the given words. It will print the count.
*
*    Estimated:  0.75 hrs
*    Actual:     0.25 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/

#include <iostream>
using namespace std;

#define WORDSIZE 256

int countLetters(char letter, char words[]);

/**********************************************************************
 * main
 * This function will prompt the user for a letter and some words
 * it will then call a function to count how many times the letter is
 * in the word. It will print the count calculated.
 ***********************************************************************/
int main()
{	
	// prompt the user for a letter
	char letter;
	cout << "Enter a letter: ";
	cin >> letter;
	cin.ignore();
	
	// prompt the user for some words
	char words[WORDSIZE];
	cout << "Enter text: ";
	cin.getline(words, WORDSIZE);
	
	// get the count and print its value
	int count = countLetters(letter, words);
	cout << "Number of '" << letter << "'s: " << count << endl;
	
	return 0;
}

/**********************************************************************
 * count letters
 * This function will count how many times the given letter appears in
 * the words given by the user
 ***********************************************************************/
int countLetters(char letter, char words[])
{
	// set count
	int count = 0;
	
	// iterate through the array
	for (int i = 0; words[i] && i < WORDSIZE; i++)
	{
		// increase the count for every letter that matches
		if (letter == words[i])
		count++;
	}
	
	return count;
}

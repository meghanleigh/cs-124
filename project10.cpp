/***********************************************************************
* Program:
*    Project 10, Mad Lib Project
*    Brother Falin, CS124
* Author:
*    Joseph Walker
* Summary:
*    
*    
*
*    Estimated:  0.0 hrs
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/
#include <cassert>
#include <iostream>
#include <fstream>

using namespace std;
void getFileName(char fileName[]);
int readFile(char fileName[], char story[][32]);
void askQuestion(char story[][32], int totalWords);
void displayStory(char story[][32], int totalWords);

int main() {
	
	char fileName[256];
	char story[256][32];
	char repeat;
	do {
		getFileName(fileName);
		int totalWords = readFile(fileName, story);
		askQuestion(story, totalWords);
		displayStory(story, totalWords);
		cout << "\nDo you want to play again (y/n)? ";
		cin >> repeat;
	} while (repeat == 'y');
	cout << "Thank you for playing.\n";

}


void getFileName(char fileName[])
{
	cout << "Please enter the filename of the Mad Lib: ";
	cin >> fileName;
	cin.ignore();
}


int readFile(char fileName[], char story[][32])
{
	ifstream fin(fileName);
	
	if (fin.fail())
	{
		return -1;
	}
	int i = 0;
	while (fin >> story[i])
	{
		i++;
	}
	
	
	return i;

}

void displayStory(char story[][32], int totalWords)
{ 
	for (int i = 0; i < totalWords; i++)
	{
		if (story[i][1] == '}')
		{
			cout << '"';
		}
		else if (story[i][1] == '{')
		{
			if (story[i - 1][1] == '#')
			{
				cout << "\"";
			}
			else {
				cout << " \"";
			}
		}
		else if (story[i][1] == ']')
		{
			cout << '\'';
		}
		else if (story[i][1] == '[')
		{
			if (story[i - 1][1] == '#')
			{
				cout << "'";
			}
			else {
				cout << " '";
			}
		}
		else if (story[i][1] == '#')
		{
			cout << "\n";
		}
		else if (i == 0)
		{
			cout << story[i];
		}
		else if (story[i][0] == ',' || story[i][0] == '.' 
				|| story[i][0] == '!' || story[i - 1][1] == '{'
				|| story[i - 1][1] == '[' || story[i - 1][1] == '#'
				|| story[i][0] == '?')
		{
			cout << story[i];
		}
		else
		{
			cout << " " << story[i];
		}
	}
}

void askQuestion(char story[][32], int totalWords)
{
	for (int i = 0; i < totalWords; i++)
	{
		if (story[i][0] == '<')
		{
			if (isalpha(story[i][1]))
			{
				cout << "\t" << (char)toupper(story[i][1]);
				for (int j = 2; story[i][j] != '>'; j++) 
				{
					if (story[i][j] == '_')
					{
						cout << " ";
					}
					else {
						cout << story[i][j];
					}
				}
				cout << ": ";
				cin.getline(story[i], 33);
				//cin >> story[i];
			}
		}
	}
	cout << "\n";
}
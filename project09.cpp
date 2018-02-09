/***********************************************************************
* Program:
*    Project 10, Mad Lib Project
*    Brother Falin, CS124
* Author:
*    Joseph Walker
* Summary:
*    Enter a brief description of your program here!  Please note that if
*    you do not take the time to fill out this block, YOU WILL LOSE POINTS.
*    Before you begin working, estimate the time you think it will
*    take you to do the assignment and include it in this header block.
*    Before you submit the assignment include the actual time it took.
*
*    Estimated:  0.0 hrs
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/

#include <iostream>
#include <fstream>

using namespace std;
void getFileName(char fileName[]);
int readFile(char fileName[], char story[][32]);
void displayStory(char story[][32], int totalWords);

int main() {
	char fileName[256];
	char story[256][32];
	getFileName(fileName);
	int totalWords = readFile(fileName, story);
	displayStory(story, totalWords);

}


void getFileName(char fileName[])
{
	cout << "Please enter the filename: ";
	cin >> fileName;
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
		
		/*
		if (the first character of story[i] is a '<' and the second
			character of story[i] is a letter)
			askQuestion(story[i]);
		*/
	}
	
	return i;

}

void displayStory(char story[][32], int totalWords)
{
	for (int i = 0; i < totalWords; i++)
	{
		// cout << ((story[i] == "<#>") ? "/n" : story[i]) << " ";
		if (story[i] == )
		{
			cout << "/n";
		}
		else if (story[i][1] == )
		{
			int count = 1;
			while (story[i][count] != )
			{
				cout << story[i][count];
				count++;
			}
			cout << " ";
			
		}
		else
		{
			cout << story[i];
		}
	}
}

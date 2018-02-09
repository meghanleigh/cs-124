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
		cout << story[i] << endl;
	}
}
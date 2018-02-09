#include <iostream>

using namespace std;

void getFileName(char fileName[]);
void readFile(char filenName[], char story[][32]);
void askQuestion(char prompt[]);

int main() {
	char fileName[256];
	char story[256][32];
	
	getFileName(fileName);
	readFile(fileName, story);
	
}
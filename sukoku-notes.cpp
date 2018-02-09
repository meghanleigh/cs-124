#include <iostream>
#include <string>

using namespace std;

#define ROWS 9
#define COLS 9

void getFilename(string & filename); // a
bool readFile(string & filename, int board[][COLS]); // b
void display(int board[][COLS]); // c
void displayOptions(); // d
void interact(int board[][COLS]); // e
void getSaveFilename(string & filename); // f
bool writeFile(string & filename, int board[][COLS]); // g
void editSquare(int board[][COLS]); // h
void getCoordinates(char coords[]); // i

bool isValid(int r, int c, int value, int board[][COLS]); // j
void getPossibleValues(int r, int c, int board[][COLS], int possilbe[]); // k



int main() {
	
	// getting the coordinates
	/*
	char column = 'B';
	char row = '3';
	
	int colIndex = column - 'A';
	int rowIndex = (int)row - '1'; 
	cout << rowIndex << endl;
	*/
}
/***********************************************************************
* Program:
*    Assignment 40, Multi-Dimesional Arrays
*    Brother Falin, CS124
* Author:
*    Joseph Walker
* Summary:
*    This program will display a tik-tak-toe board
*
*    Estimated:  0.75 hrs
*    Actual:     0.5 hrs
*      Gett the display to work correctly
************************************************************************/

#include <fstream>
#include <iostream>

using namespace std;

#define ROWS 3
#define COLS 3

void getFilename(char filename[]);
void loadFile(char filename[], char game[][COLS]);
void displayGame(char game[][COLS]);
void getSaveFilename(char filename[]);
void saveGame(char filename[], char game[][COLS]);

/**********************************************************************
 * main
 * this function will create the environment for the other program to
 * run properly.
 ***********************************************************************/
int main() {
	char filename[256];
	char game[ROWS][COLS];
	
	getFilename(filename);
	loadFile(filename, game);
	displayGame(game);
	
	getSaveFilename(filename);
	saveGame(filename, game);
}

/**********************************************************************
 * display game
 * this function will display the game board and answers from file
 ***********************************************************************/
void displayGame(char game[][COLS])
{
	for (int r = 0; r < ROWS; r++)
	{
		for (int c = 0; c < COLS; c++)
		{
			cout << " "
				 << (game[r][c] == '.' ? ' ' : game[r][c])
				 << " ";
			if (c < COLS - 1)
				cout << "|";
		}
		cout << endl;
		if (r < ROWS - 1)
			cout << "---+---+---" << endl;
	}
	
}

/**********************************************************************
 * load file
 * this function will load the file and store it in the game array
 ***********************************************************************/
void loadFile(char filename[], char game[][COLS])
{
	ifstream fin(filename);
	
	if (fin.fail()){
		return;
	}

	for (int r = 0; r < 3; r++)
	{
		for (int c = 0; c < 3; c++)
		{
			fin >> game[r][c];
		}
	}
	fin.close();
}

/**********************************************************************
 * get filename
 * This function will prompt the user for the filename
 ***********************************************************************/
void getFilename(char filename[])
{
	cout << "Enter filename: ";
	cin >> filename; 
}

/**********************************************************************
 * save game
 * this function will save the game into a new file
 ***********************************************************************/
void saveGame(char filename[], char game[][COLS])
{
	ofstream fout(filename);
		
		if (fout.fail())
			return;
			
		for (int r = 0; r < 3; r++)
		{
			for (int c = 0; c < 3; c++)
			{
				fout << game[r][c];
				if (c < COLS -1)
					fout << " ";
			}
			if (r < ROWS - 1)
				fout << endl;
		}
		fout.close();
}

/**********************************************************************
 * get save filname
 * this function will get the filename for the new save file.
 ***********************************************************************/
void getSaveFilename(char filename[])
{
	cout << "Enter desitination filename: ";
	cin >> filename;
}
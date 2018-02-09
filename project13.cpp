/***********************************************************************
* Program:
*    Project 13, Sudoku Project
*    Brother Falin, CS124
* Author:
*    Joseph Walker
* Summary:
*    This program will emulate the math puzzle known as Sudoku. The
*    program will give the user a list of actions that can be completed
*	 in the program. The user can load a game board, edit the data on
*	 the board, see possible values for a square in the puzzle, and
*	 save the added board data to a file on their computer.
*    
*
*    Estimated:  4.0 hrs
*    Actual:     2.0 hrs
*      getting the possible values for the square of the coordinates
************************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
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
void getCoordinates(string & coords); // i
bool isValid(int r, int c, string & coords, int board[][COLS]); // j
void showPossibleValues(int board[][COLS]);
void getPossibleValues(int r, int c, int board[][COLS], int possilbe[]); // k

/**********************************************************************
 * main
 * Starts program by retrieving the filename and game board data
 * Initializes user interaction and save game file procedure when the
 * program ends.
 ***********************************************************************/
int main() {
	string filename;
	int board[ROWS][COLS];

	getFilename(filename);
	readFile(filename, board);
	interact(board);
	getSaveFilename(filename);
	if (writeFile(filename, board))
	{
		cout << "Board written successfully" << endl;
	}
}

/**********************************************************************
 * get filename
 * Prompts the user for the name of the file where the board is saved
 ***********************************************************************/
void getFilename(string & filename)
{
	cout << "Where is your board located? ";
	cin >> filename;
	cin.ignore();
}

/**********************************************************************
 * read file
 * stores the data from the file into a two dimensional array
 ***********************************************************************/
bool readFile(string & filename, int board[][COLS])
{
	ifstream fin(filename.c_str());
	
	if (fin.fail())
	{
		return false;
	}
	else
	{
		for (int r = 0; r < ROWS; r++)
		{
			for (int c = 0; c < COLS; c++)
			{
				fin >> board[r][c];
			}
		}
		return true;
	}
	fin.close();
}

/**********************************************************************
 * display
 * prints the game board with the loaded data from the given file
 ***********************************************************************/
void display(int board[][COLS])
{
	cout << "   A B C D E F G H I\n";
	for (int r = 0; r < ROWS; r++)
	{
		cout << setw(3) << left << r + 1;
		for (int c = 0; c < COLS; c++)
		{
			if ((c + 1) % 3 == 0 && (c + 1) % 9 != 0)
			{
				if (board[r][c] == 0)
				{
					cout << " |";
				}
				else {
					cout << board[r][c] << "|";
				}

			}
			else if ((c + 1) % 9 == 0)
			{
				if (board[r][c] == 0)
				{
					cout << " \n";
				}
				else {
					cout << board[r][c] << "\n";
				}
			}
			else
			{
				if (board[r][c] == 0)
				{
					cout << "  ";
				}
				else {
					cout << board[r][c] << " ";
				}
			}
		}
		if ((r + 1) % 3 == 0 && (r + 1) % 9 != 0)
		{
			cout << "   -----+-----+-----\n";
		}
	}
	cout << endl;
}

/**********************************************************************
 * interact
 * prompts the user for the game option desired and performs the 
 * corresponding tasks.
 ***********************************************************************/
void interact(int board[][COLS])
{
	char option;
	displayOptions();
	cout << endl;
	display(board);
	do
	{
		cout << "> ";
		cin >> option;
		switch (option)
		{
			case '?':
				displayOptions();
				cout << endl;
				break;
			case 'D':
			case 'd':
				display(board);
				break;
			case 'E':
			case 'e':
				editSquare(board);
				break;
			case 'S':
			case 's':
				showPossibleValues(board);
				break;
			case 'Q':
			case 'q':
				break;
			default:
				cout << "ERROR: Invalid command\n";
				break;
		}
	} while (toupper(option) != 'Q');
}

/**********************************************************************
 * display options
 * prints the game options and commands for the user
 ***********************************************************************/
void displayOptions()
{
	cout << "Options:" << endl;
	cout << "   ?  Show these instructions" << endl;
	cout << "   D  Display the board" << endl;
	cout << "   E  Edit one square" << endl;
	cout << "   S  Show the possible values for a square" << endl;
	cout << "   Q  Save and Quit" << endl;
}

/**********************************************************************
 * get save filename
 * prompts the user for the location of the file the data will be
 * written to.
 ***********************************************************************/
void getSaveFilename(string & filename)
{
	cout << "What file would you like to write your board to: ";
	cin >> filename;
	cin.ignore();
}

/**********************************************************************
 * write file
 * saves the game board data to a file in a nine by nine grid
 ***********************************************************************/
bool writeFile(string & filename, int board[][COLS])
{
	ofstream fout(filename.c_str());
			
			if (fout.fail())
				return false;
				
			for (int r = 0; r < ROWS; r++)
			{
				for (int c = 0; c < COLS; c++)
				{
					fout << board[r][c];
					if (c < COLS -1)
						fout << " ";
				}
				if (r < ROWS - 1)
					fout << endl;
			}
			fout.close();
	return true;
}

/**********************************************************************
 * edit square
 * inserts a new value into an empty area of the game board
 ***********************************************************************/
void editSquare(int board[][COLS])
{
	string coords;
	int c = 0;
	int r = 0;
	getCoordinates(coords);
	c = toupper(coords[0]) - 'A';
	r = (int)coords[1] - '1';
	coords[0] = toupper(coords[0]);
	bool validInput = false;
	if (isValid(r, c, coords, board))
	{
		int possible[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
		int value;
		cout << "What is the value at '" << coords[0]
				 << coords[1] << "': ";
		cin >> value;
		getPossibleValues(r, c, board, possible);
		for (int i = 0; i < 9; i++)
		{	
			if (value == possible[i])
			{
				//cout << r << " " << c << endl;
				board[r][c] = value;
				//cout << "check 1"<< endl;
				validInput = true;
				cout << endl;
			}
		}
		if (!validInput)
		{
			cout << "ERROR: Value '" << value << "' in square '" << coords[0] 
				 << coords[1] << "' is invalid\n" << endl;
		}
	}
}

/**********************************************************************
 * get coordinates
 * Prompts the user for the coordinates on the grid that they need
 ***********************************************************************/
void getCoordinates(string & coords)
{
	cout << "What are the coordinates of the square: ";
	cin >> coords[0];
	cin >> coords[1];
}

/**********************************************************************
 * is valid
 * checks if the coordinate being selected already contains a value
 ***********************************************************************/
bool isValid(int r, int c, string & coords, int board[][COLS])
{

	if (board[r][c] != 0)
	{
		cout << "ERROR: Square '" << coords[0] << coords[1]
				 << "' is filled\n" << endl;
		return false;
	}
	return true;
}

/**********************************************************************
 * show possible values
 * prints the possible values for a specified coordinate of game board
 ***********************************************************************/
void showPossibleValues(int board[][COLS])
{
	string coords;
	getCoordinates(coords);
	int c = toupper(coords[0]) - 'A';
	int r = (int)coords[1] - '1';
	
	// make a list of possible inputs
	int possible[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	getPossibleValues(r, c, board, possible);
	coords[0] = toupper(coords[0]);
	
	// print all of the possible input values for the sqaure
	cout << "The possible values for " << coords[0] << coords[1]
			 << " are: ";
	
	int count = 0;
	for (int i = 0; i < 9; i++)
	{
		if (possible[i] != 0)
		{
			// print out the value with the proper spacing
			++count;
			if (count == 1)
			{
				// the first value printed will not have a
				// preceding comma or space
				cout << possible[i];
			}
			else
			{
				cout << ", " << possible[i];
			}
		}
	}
	cout << endl;
}


/**********************************************************************
 * get possible values
 * calculates the possible values for a specified location
 ***********************************************************************/
void getPossibleValues(int r, int c, int board[][COLS], int possible[])
{
	// set left, right, top and bottom borders for the square coordinates
	int left = c / 3 * 3;
	int right = left + 2;
	int top = r / 3 * 3;
	int bottom = top + 2;
	
	// find already used values in the square
	for (int row = top; row <= bottom; row++)
	{
		for (int col = left; col <= right; col++)
		{
			int value = board[row][col];
			possible[value - 1] = 0;
		}
	}
	
	// find already used values in the row
	for (int col = 0; col < COLS; col++)
	{
		int value = board[r][col];
		possible[value - 1] = 0;
	}
	
	// find already used values in the column
	for (int row = 0; row < ROWS; row++)
		{
			int value = board[row][c];
			possible[value - 1] = 0;
		}
}

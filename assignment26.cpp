/***********************************************************************
* Program:
*    Assignment 26, IF STATEMENTS
*    Brother Falin, CS124
* Author:
*    Joseph Walker
* Summary:
*   start
*   
*
*    Estimated:  0.0 hrs
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/

#include <iostream>
#include <fstream>

using namespace std;

void getFileName(char fileName[])
{
	cout << "Please enter the filename: ";
	cin >> fileName;
}

int readFile(char fileName[])
{
	ifstream fin(fileName);

	if(fin.fail())
		{
			return -9999;
		}
	int grade;

	float sum = 0;
	float count = 0;

	while(fin >> grade)
		{
			sum += grade;
			count++;
		}
	return sum / count;
}

void display(float average, char fileName[])
{
	if (average < 0)
	{
		cout << "Error reading file "  << fileName << endl;
	}
	else 
	{
		cout << "Average Grade: " << average << endl;
	}
}
/**********************************************************************
 * 
 * 
 ***********************************************************************/
int main()
{
	char fileName[12];
	getFileName(fileName);
	int average = readFile(fileName);
	display(average, fileName);
	return 0;
}

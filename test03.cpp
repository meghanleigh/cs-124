/***********************************************************************
* Program:
*    Test 3, Reverse a List
*    Brother Falin, CS124
* Author:
*    Joseph Walker
* Summary:
*    This program is supposed to reverse a list.
*
*    Estimated:  0.0 hrs
*    Actual:     0.0 hrs
*      reversing the list.
************************************************************************/

#include <iostream>
#include <fstream>

using namespace std;
void getFileName(char fileName[]);
int readFile(char fileName[], char prices[][10], char reversePrices[][10]);
void displayPrices(char prices[][10], int size);

int main() {
	char fileName[256];
	char prices[100][10];
	char reversePrices[100][10];
	getFileName(fileName);
	int size = readFile(fileName, prices, reversePrices);
	displayPrices(prices, size);

}


void getFileName(char fileName[])
{
	cout << "Enter the filename: ";
	cin >> fileName;
}


int readFile(char fileName[], char prices[][10], char reversePrices[][10])
{
	ifstream fin(fileName);
	
	if (fin.fail())
	{
		return -1;
	}
	
	int i = 0;
	while (fin >> prices[i])
	{
		i++;
	}
	int count = i;
	int j = 0;
	char swap[100];
	while (i > 0) {
		reversePrices[j] = prices[i];
		i--;
		j++;
	}
	return count;

}

void displayPrices(char prices[][10], int size)
{
	cout << "New order: " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << prices[i] << endl;
	}
}
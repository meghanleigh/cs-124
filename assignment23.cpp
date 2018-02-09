/***********************************************************************
* Program:
*    Assignment 23, Loop Syntax
*    Brother Falin, CS124
* Author:
*    Joseph Walker
* Summary:
*    This program will find the sum of any number's multiples that are
*    less than 100.
*
*    Estimated:  0.75 hrs
*    Actual:     0.10 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * main
 * this function will prompt the user for a number and find the sum of
 * all of it's multiples less than 100.
 ***********************************************************************/
int main()
{
	cout << "What multiples are we adding? ";
	int sum = 0;
	int multiple;
	cin >> multiple;
	
	for(int i = multiple; i < 100; i += multiple) {
		sum += i;
	}
	
	cout << "The sum of multiples of " << multiple
		 << " less than 100 are: " << sum << endl;
	
}

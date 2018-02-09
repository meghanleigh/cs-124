/**************************************************
* Program:
*    Test 1,
*    Brother Falin, CS124
* Author:
*    Joseph Walker
* Summary:
*    This program will evaluate the user's practice test
*    score and determine if more studying is required.
************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
* Main
* Will prompt the user for their practice final score and then evaluate
* the score to determine if more studying is required.
***********************************************************************/
int main()
{
	float score;
	cout << "What was your score on the practice final in percentage points? ";
	cin >> score;

	if (score < 85)
	{
		cout << "\tMore studying is required.\n";
	}
	else
	{
		cout << "\tYou are ready to take the test!\n";
	}
	return 0;
}

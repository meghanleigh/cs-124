/***********************************************************************
* Program:
*    Assignment 33, Pointers
*    Brother Falin, CS124
* Author:
*    Joseph Walker
* Summary:
*    
*	
*	
*
*    Estimated:  0.75 hrs
*    Actual:     0.30 hrs
*      Getting the pointer to work.
************************************************************************/

#include <iostream>

using namespace std;

float getSamBalance();
float getSueBalance();
void date(float* pAccount);

/**********************************************************************
 * main
 * this function will retrieve the balances, evaluate who has more 
 * money, then retrieve and print the new balances after the cost of
 * the date.
 ***********************************************************************/
int main() {
	float sam = getSamBalance();
	float sue = getSueBalance();
	float* richPersonAccount;
	
	// assign the pointer to the person with the largest balance
	if (sam > sue)
		richPersonAccount = &sam;
	else
		richPersonAccount = & sue;
	
	// find the cost and new balance
	date(richPersonAccount);
	
	// print post-date balances.
	cout << "Sam's balance: $" << sam << endl;
	cout << "Sue's balance: $" << sue << endl;
	
}

/**********************************************************************
 * date
 * get the cost of the date and subtract it from the balance of the
 * person with the larger balance
 ***********************************************************************/
void date(float* pAccount)
{
	cout << "Cost of the date:" << endl;
	float dinner;
	float movie;
	float iceCream;
	
	// get individual costs
	cout << "\tDinner:\t\t";
	cin >> dinner;
	
	cout << "\tMovie:\t\t";
	cin >> movie;
	
	cout << "\tIce cream:\t";
	cin >> iceCream;
	
	// get the sum of the costs
	float total = dinner + movie + iceCream;
	
	// subtract it from the balance.
	*pAccount -= total;
}

/**********************************************************************
 * Get Sam Blance
 * prompt the user for Sam's balnce, store it, and return it
 ***********************************************************************/
float getSamBalance()
{
	float balance;
	cout << "What is Sam's balance? ";
	cin >> balance;
	return balance;
}

/**********************************************************************
 * Get Sue Blance
 * prompt the user for Sue's balnce, store it, and return it
 ***********************************************************************/
float getSueBalance()
{
	float balance;
	cout << "What is Sue's balance? ";
	cin >> balance;
	return balance;
}
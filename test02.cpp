/***********************************************************************
* Program:
*    Test 2, Compound Interest
*    Brother Falin, CS124
* Author:
*    Joseph Walker
* Summary:
*    This program will calculate the growth of investments over time
*	 based on the annual yeild of the investment and years invested.
*
*    Estimated:  1.0 hrs
*    Actual:     0.0 hrs
*      
************************************************************************/

#include <iostream>
using namespace std;

double getAmount();
double getInterest();
int getYears();
void calculateGrowth(double amount, double interest, int years);


/**********************************************************************
 * main
 * This function will initiate the program calling the getAmount, 
 * getInterest, and getYears functions followed by the calculateGrowth
 * function.
 ***********************************************************************/
int main()
{
	double amount = getAmount();
	double interest = getInterest();
	int years = getYears();
	
	calculateGrowth(amount, interest, years);
	return 0;
}

/**********************************************************************
 * Get Amount
 * This function will prompt the user for the investment amount
 ***********************************************************************/
double getAmount()
{
	double amount;
	// prompt user for amount
	cout << "How much are you investing? ";
	cin >> amount;
	return amount;
}

/**********************************************************************
 * Get Interest
 * This function will prompt the user for the interest rate that their
 * investment yeilds annually.
 ***********************************************************************/
double getInterest()
{
	double interest;
	// prompt the user for the annual interest rate
	cout << "What is the interest rate in percent? ";
	cin >> interest;
	return interest;
}

/**********************************************************************
 * Get Years
 * This function will prompt the user for the amount of years that
 * they plan on acumulating the annual yeild.
 ***********************************************************************/
int getYears()
{
	int years;
	// prompt the user for the amount of time in years
	cout << "How long will this investment grow in years? ";
	cin >> years;
	return years;
}

/**********************************************************************
 * Calculate Growth
 * This function will calculate the future growth of the user's
 * investment. It will also print the result of the calculation.
 ***********************************************************************/
void calculateGrowth(double amount, double interest, int years)
{
	// format the console output appropriate for currency
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	
	// convert interest into decimal value
	double interestRate = interest / 100;
	double growth = amount;
	
	// loop through each year and add the 
	// annual yeild to the total growth
	for (int i = 1; i <= years; i++)
	{
		growth += (growth * interestRate);
	}
	
	// print the result to the console
	cout << "At the end of " << years 
		 << " years, you will have $" << growth;
}
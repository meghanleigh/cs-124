/***********************************************************************
* Program:
*    Assignment 16, IF STATEMENTS
*    Brother Falin, CS124
* Author:
*    Joseph Walker
* Summary:
*    This program evaluates the tax bracket of the user based on their
*    income.
*
*    Estimated:  0.75 hrs
*    Actual:     0.25 hrs
*      getting the program to recognize the first boolean expression.
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * Compute Tax
 * This function returns the tax bracket that the user's income falls
 * into.
 ***********************************************************************/
int computeTax(float income)
{
  if (income > 0 && income <= 15100)
    {
      return 10;    
    }
  else if (income > 15100 && income <= 61300)
    {
      return 15;
    }
  else if (income > 61300 && income <= 123700)
    {
      return 25;
    }
  else if (income > 123700 && income <= 188450)
    {
      return 28;
    }
  else if (income > 188450 && income <= 336550)
    {
      return 33;
    }
  else
    {
      return 35;
    }
}

/**********************************************************************
 * Main
 * This function will prompt the user for their income and output their
 * tax bracket.
 ***********************************************************************/
int main()
{
  float income;
  cout << "Income: ";
  cin >> income;

  int tax = computeTax(income);

  cout << "Your tax bracket is " << tax << "%\n";

	return 0;
}

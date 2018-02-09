#include <iomanip>
#include <iostream>
using namespace std;

/**********************************************************************
* Get Income
* This function will prompt the User for their personal Income
***********************************************************************/
float getIncome(float income)
{
	cout << "\tYour monthly income: ";
	cin >> income;
	return income;
}

/**********************************************************************
* Get Budget Living
* This function will prompt the User for their budgeted living expenses
***********************************************************************/
float getBudgetLiving(float budgetLiving)
{
	cout << "\tYour budgeted living expenses: ";
	cin >> budgetLiving;
	return budgetLiving;
}

/*********************************************************************
* Get Actual Living
* This function will prompt the User for their actual living expenses.
***********************************************************************/
float getActualLiving(float actualLiving)
{
	cout << "\tYour actual living expenses: ";
	cin >> actualLiving;
	return actualLiving;
}

/**********************************************************************
* Get Actual Tax
* This function will prompt the User for their actual tax expense.
***********************************************************************/
float getActualTax(float tax)
{
	cout << "\tYour actual taxes withheld: ";
	cin >> tax;
	return tax;
}

/**********************************************************************
 * Get Actual Tithing
 * This function will prompt the User for their actual tithe offerings.
 ***********************************************************************/
float getActualTithing(float tithing)
{
	cout << "\tYour actual tithe offerings: ";
	cin >> tithing;
	return tithing;
}

/**********************************************************************
 * Get Actual Other
 * This function will prompt the User for their actual other expenses.
 ***********************************************************************/
float getActualOther(float other)
{
	cout << "\tYour actual other expenses: ";
	cin >> other;
	return other;
}

/**********************************************************************
 * Compute Tithing
 * This function will compute the minimum tithing that the user should
 * pay.
 ***********************************************************************/
float computeTithing(float income)
{
	return income * .1;
}

/**********************************************************************
 * Compute Tax
 * This function will calculate the expected taxes withheld for the user
 ***********************************************************************/
float computeTax(float income)
{
  float budgetTax = income * 0;
	return budgetTax;
}

/**********************************************************************
 * Budget Other
 * This function will calculate how much is left over for other
 * expenses on the monthly budget.
 ***********************************************************************/
float budgetOther(float income, float budgetLiving)
{
	return income - (computeTax(income) + computeTithing(income) + budgetLiving);
}

/**********************************************************************
 * Display
 * This function will display a report of the User's monthly expenses.
 ***********************************************************************/
void display(float income, float budgetLiving, float actualLiving, float tax, float tithing, float other)
{
  cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

  cout << "\nThe following is a report on your monthly expenses"
       << endl;

  cout << "\t" << setw(22) << left << "Item"
       << setw(10) << left << "Budget"
       << setw(12) << right << "Actual\n";

  cout << "\t" << "=============== =============== ===============\n";

  cout << "\t" << setw(16) << left << "Income"
       << setw(1) << "$"
       << setw(11) << right << income
       << setw(5) << right << "$"
       << setw(11) << right << income
       << endl;

  cout << "\t" << setw(16) << left << "Taxes"
       << setw(1) << "$"
       << setw(11) << right << computeTax(income)
       << setw(5) << right << "$"
       << setw(11) << right << tax
       << endl;

  cout << "\t" << setw(16) << left << "Tithing"
       << setw(1) << "$"
       << setw(11) << right << computeTithing(income)
       << setw(5) << right << "$"
       << setw(11) << right << tithing
       << endl;

  cout << "\t" << setw(16) << left << "Living"
       << setw(1) << "$"
       << setw(11) << right << budgetLiving
       << setw(5) << right << "$"
       << setw(11) << right << actualLiving
       << endl;

  cout << "\t" << setw(16) << left << "Other"
       << setw(1) << "$"
       << setw(11) << right << budgetOther(income, budgetLiving)
       << setw(5) << right << "$"
       << setw(11) << right << other
       << endl;

  cout << "\t" << "=============== =============== ==============="
       << endl;

  cout << "\t" << setw(16) << left << "Difference"
       << setw(1) << "$"
       << setw(11) << right << income - (computeTax(income) + computeTithing(income) + budgetLiving + budgetOther(income, budgetLiving))
       << setw(5) << right << "$"
       << setw(11) << right << income - (tax + tithing + actualLiving + other)
       << endl;
}

/**********************************************************************
* Add text here to describe what the function "main" does. Also don't forget
* to fill this out with meaningful text or YOU WILL LOSE POINTS.
***********************************************************************/
int main()
{
	cout << "This program keeps track of your monthly budget\n"
		   << "Please enter the following:\n";
	float income = getIncome(income);
	float budgetLiving = getBudgetLiving(budgetLiving);
	float actualLiving = getActualLiving(actualLiving);
	float tax = getActualTax(tax);
	float tithing = getActualTithing(tithing);
	float other = getActualOther(other);

	display(income, budgetLiving, actualLiving, tax, tithing, other);
	return 0;
}

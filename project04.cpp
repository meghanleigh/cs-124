/***********************************************************************
* Program:
*    Project 04, Monthly Budget
*    Brother Falin, CS124
* Author:
*    Joseph Walker
* Summary:
*    This program will assist a user at make and track their monthly
*    budget.
*
*    Estimated:  4.0 hrs
*    Actual:     2.0 hrs
*      The hardest part was making the display function look correct.
************************************************************************/
#include <iomanip>
#include <iostream>
using namespace std;

/**********************************************************************
* Get Income
* This function will prompt the User for their personal Income
***********************************************************************/
double getIncome(double income)
{
   cout << "\tYour monthly income: ";
   cin >> income;
   return income;
}

/**********************************************************************
* Get Budget Living
* This function will prompt the User for their budgeted living expenses
***********************************************************************/
double getBudgetLiving(double budgetLiving)
{
   cout << "\tYour budgeted living expenses: ";
   cin >> budgetLiving;
   return budgetLiving;
}

/*********************************************************************
* Get Actual Living
* This function will prompt the User for their actual living expenses.
***********************************************************************/
double getActualLiving(double actualLiving)
{
   cout << "\tYour actual living expenses: ";
   cin >> actualLiving;
   return actualLiving;
}

/**********************************************************************
* Get Actual Tax
* This function will prompt the User for their actual tax expense.
***********************************************************************/
double getActualTax(double tax)
{
   cout << "\tYour actual taxes withheld: ";
   cin >> tax;
   return tax;
}

/**********************************************************************
* Get Actual Tithing
* This function will prompt the User for their actual tithe offerings.
***********************************************************************/
double getActualTithing(double tithing)
{
   cout << "\tYour actual tithe offerings: ";
   cin >> tithing;
   return tithing;
}

/**********************************************************************
* Get Actual Other
* This function will prompt the User for their actual other expenses.
***********************************************************************/
double getActualOther(double other)
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
double computeTithing(double income)
{
   return income * .1;
}

/**********************************************************************
* Compute Tax
* This function will calculate the expected taxes withheld for the user
***********************************************************************/
double computeTax(double income)
{
   double yearlyIncome = income * 12;
   double yearlyTax;

   if (yearlyIncome >= 0 && yearlyIncome < 15100)
     {
       yearlyTax = yearlyIncome * 0.10;
     }
   else if (yearlyIncome >= 15100 && yearlyIncome < 61300)
     {
       yearlyTax = 1510 + 0.15 * (yearlyIncome - 15100);
     }
   else if (yearlyIncome >= 61300 && yearlyIncome < 123700)
     {
       yearlyTax = 8440 + 0.25 * (yearlyIncome - 61300);
     }
   else if (yearlyIncome >= 123700 && yearlyIncome < 188450)
     {
       yearlyTax = 24040 + 0.28 * (yearlyIncome - 123700);
     }
   else if (yearlyIncome >= 188450 && yearlyIncome < 336550)
     {
       yearlyTax = 42170 + 0.33 * (yearlyIncome - 188450);
     }
   else
     {
       yearlyTax = 91043 + 0.35 * (yearlyIncome - 336550);
     }

   double monthlyTax = yearlyTax / 12;

   return monthlyTax;
}

/**********************************************************************
* Budget Other
* This function will calculate how much is left over for other
* expenses on the monthly budget.
***********************************************************************/
double budgetOther(double income, double budgetLiving)
{
   return income - (computeTax(income) + computeTithing(income)
                         + budgetLiving);
}

/**********************************************************************
* Display
* This function will display a report of the User's monthly expenses.
***********************************************************************/
void display(double income,
             double budgetLiving,
             double actualLiving,
             double tax,
             double tithing,
             double other)
{
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);

  cout << "\nThe following is a report on your monthly expenses"
       << endl;

  cout << "\t" << setw(22) << left << "Item"
       << setw(10) << left << "Budget"
       << setw(12) << right << "Actual"
       << endl;

  cout << "\t" << "=============== =============== ==============="
       << endl;

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
       << setw(11) << right
       << income - (computeTax(income)
                    + computeTithing(income)
                    + budgetLiving
                    + budgetOther(income, budgetLiving))
       << setw(5) << right << "$"
       << setw(11) << right
       << income - (tax + tithing + actualLiving + other)
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
  double income = getIncome(income);
  double budgetLiving = getBudgetLiving(budgetLiving);
  double actualLiving = getActualLiving(actualLiving);
  double tax = getActualTax(tax);
  double tithing = getActualTithing(tithing);
  double other = getActualOther(other);

  display(income, budgetLiving, actualLiving, tax, tithing, other);
  return 0;
}



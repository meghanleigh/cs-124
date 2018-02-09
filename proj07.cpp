/***********************************************************************
* Program:
*    Project 07, Calendar
*    Brother Falin, CS124
* Author:
*    Joseph Walker
* Summary:
*    
*    
*    
*    
*    
*
*    Estimated:  0.0 hrs
*    Actual:     0.0 hrs
*      Calculating the Offset
************************************************************************/
#include <iostream>
#include <iomanip>
using namespace std;

int getMonth();
int getYear();
void display(int month, int year);
void monthAndYear(int month, int year);
int calculateDaysInWholeYears(int year);
int daysInMonth(int month, int year);
int calculateOffset(int month, int year);
bool isLeapYear(int year);
int calculateDaysPastThisYear(int month, int year);


/**********************************************************************
 * Main
 * This function will initialize the program and call the functions
 * required to display the calendar
 ***********************************************************************/
int main()
{
	int month = getMonth();
	int year = getYear();
	display(month, year);
	return 0;
}

/**********************************************************************
 * get month
 * Will prompt the user for a month and verify that the input is a valid
 ***********************************************************************/
int getMonth()
{
	int month;
	bool validMonth = true;
	// continue to prompt the user until a valid month is given
	do
	{
		cout << "Enter a month number: ";
		cin >> month;
		if (month > 12 || month < 1)
		{
			cout << "Month must be between 1 and 12.\n";
		}
		else
		{
			validMonth = false;
		}
	} while (validMonth);
	
	return month;	
}

/**********************************************************************
 * get year
 * Will prompt the user for a year and verify that the input is a valid
 ***********************************************************************/
int getYear()
{
	int year;
	bool validYear = true;
	//continue to prompt the user until a year of 1753 or later is given
	do
	{
		cout << "Enter year: ";
		cin >> year;
		if (year < 1753)
		{
			cout << "Year must be 1753 or later.\n";
		}
		else
		{
			validYear = false;
		}
	} while (validYear);

	return year;
}

/**********************************************************************
 * display
 * display the calendar for the given year and month
 ***********************************************************************/
void display(int month, int year)
{
	int offset = calculateOffset(month, year);
	int numDays = daysInMonth(month, year);
	monthAndYear(month, year);
	
	cout << "  Su  Mo  Tu  We  Th  Fr  Sa" << endl;
		
		if (offset != 6)
			cout << setw((offset + 1) * 4) << "";
		
		for (int i = 1; i <= numDays; i++)
			{
				cout << setw(4) << i;
			
				if ((i + offset + 1) % 7 == 0 && i != numDays)
					{
						cout << endl;
					}
			}
		cout << endl;
}

/**********************************************************************
 * month and year
 * Print the name of the month and the given year as a title for the
 * calendar.
 ***********************************************************************/
void monthAndYear(int month, int year)
{
	if (month == 1)
	{
		cout << "\nJanuary, " << year << endl;
	}
	else if (month == 2)
	{
		cout << "\nFebruary, " << year << endl;
	}
	else if (month == 3)
	{
		cout << "\nMarch, " << year << endl;
	}
	else if (month == 4)
	{
		cout << "\nApril, " << year << endl;
	}
	else if (month == 5)
	{
		cout << "\nMay, " << year << endl;
	}
	else if (month == 6)
	{
		cout << "\nJune, " << year << endl;
	}			
	else if (month == 7)
	{
		cout << "\nJuly, " << year << endl;
	}
	else if (month == 8)
	{
		cout << "\nAugust, " << year << endl;
	}
	else if (month == 9)
	{
		cout << "\nSeptember, " << year << endl;
	}
	else if (month == 10)
	{
		cout << "\nOctober, " << year << endl;
	}
	else if (month == 11)
	{
		cout << "\nNovember, " << year << endl;
	}
	else
	{
		cout << "\nDecember, " << year << endl;
	}
}

/**********************************************************************
 * calculate offset
 * calculate the offset for the calendar days in the calendar
 ***********************************************************************/
int calculateOffset(int month, int year)
{
	int daysInYears = calculateDaysInWholeYears(year);
	int daysInCurrentYear = calculateDaysPastThisYear(month, year);
	// calculate the offset
	int offset = (daysInYears + daysInCurrentYear) % 7;
	
	return offset;
}

/**********************************************************************
 * calculate days in whole years
 * calculate the amount of days in the years between 1753 and the given
 * year
 ***********************************************************************/
int calculateDaysInWholeYears(int year)
{
 	int daysInYears = 0;
	for (int i = 1753; i < year; i++)
	{
		// add the correct number of days for each year
		if (isLeapYear(i))
		{
			daysInYears += 366;
		}
		else
		{
			daysInYears += 365;
		}
	}
	return daysInYears;
}

/**********************************************************************
 * calculate days past this year
 * calculate the amount of days past in the year leading up to the 
 * given month.
 ***********************************************************************/
int calculateDaysPastThisYear(int month, int year)
{
	int daysInCurrentYear = 0;
	for (int i = 1; i < month; i++)
	{
		daysInCurrentYear += daysInMonth(i, year);
	}
	
	return daysInCurrentYear;
}

/**********************************************************************
 * days in month
 * evaluate how many days are in the month
 ***********************************************************************/
int daysInMonth(int month, int year)
{
	int days = 0;
	if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		days = 30;
	}
	else if (month == 2)
	{
		if (isLeapYear(year))
		{
			days = 29;
		}
		else
		{
			days = 28;
		}
	}
	else
	{
		days = 31;
	}
	
	return days;

}

/**********************************************************************
 * is leap year
 * determine whether the year is a leap year or not
 ***********************************************************************/
bool isLeapYear(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
	{
		return true;
	}
	
	else
	{
		return false;
	}
}

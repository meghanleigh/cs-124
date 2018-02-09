#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	
	int month;
	int year;
	cout << "Enter Month: ";
	cin >> month;
	cout << "Enter Year: ";
	cin >> year;
	
	int days;
	
	if (month == 4 || month == 6 || month == 9 || month == 11) {
		days = 30;
	}
	else if (month == 2) {
			if ((((year % 4 ) == 0) && (year % 100 != 0)) || (year % 400 == 0))
			{
				days = 29;
			}
			else {
				days = 28;
			}
	}
	else {
		days = 31;
	}
	
	for (int countYear = 1753; countYear < year; countYear++){
		
	}
	
	int offset = 6;
	
	
	
	cout << "  Su  Mo  Tu  We  Th  Fr  Sa" << endl;
	
	if(offset != 6)
		cout << setw((offset + 1) * 4) << "";
	
	for(int i = 1; i <= days; i++)
	{
		cout << setw(4) << i;
		
		if((i + offset + 1) % 7 == 0)
		{
			cout << endl;
		}
	}
}

bool isLeapYear(year) {
	if ((year % 4 ) == 0) && (year % 100 != 0) || (year % 400 == 0))
}

int daysInMonth(int month, int year) {
	if (month == 4 || month == 6 || month == 9 || month == 11) {
		days = 30;
	}
	else if (month == 2) {
			if (isLeapYear(year))
			{
				days = 29;
			}
			else {
				days = 28;
			}
	}
	else {
		days = 31;
	}
}

int calculateNumberOfDaysThisYear(int targetMonth, int year)
{
	int totalDays = 0;
	
	for(int month = 1)	
}
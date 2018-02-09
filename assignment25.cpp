/***********************************************************************
* Program:
*    Assignment 25, Loop Design
*    Brother Falin, CS124
* Author:
*    Joseph Walker
* Summary:
*    This program will display a calendar table based of the number of
*    days in the month and the offset of the starting day of the month.
*
*    Estimated:  0.75 hrs
*    Actual:     0.15 hrs
*      Getting the line spacing to be correct
************************************************************************/
#include <iomanip>
#include <iostream>
using namespace std;

/**********************************************************************
 * Display Table
 * This function will display the calendar table with the correct offset
 ***********************************************************************/
void displayTable(int numDays, int offset)
{


  cout << "  Su  Mo  Tu  We  Th  Fr  Sa" << endl;
	
	if(offset != 6)
		cout << setw((offset + 1) * 4) << "";
	
	for(int i = 1; i <= numDays; i++)
    {
      cout << setw(4) << i;
		
      if((i + offset + 1) % 7 == 0 && i != numDays)
        {
          cout << endl;
        }
    }
  cout << endl;
}



/**********************************************************************
 * Main
 * Will prompt the user for the number of days in the month and the
 * offset. It will then call the displayTable function.
 ***********************************************************************/
int main()
{
  int numDays;
  int offset;
  cout << "Number of Days: ";
  cin >> numDays;

  cout << "Offset: ";
  cin >> offset;

  displayTable(numDays, offset);
  
  cout << 365 % 7;
  

	return 0;
}

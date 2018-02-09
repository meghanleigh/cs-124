/***********************************************************************                                 
* Program:                                                                                               
*    Assignment 11, Output monthly budget                                                                
*    Brother Falin, CS124                                                                                
* Author:                                                                                                
*    Joseph Walker                                                                                       
* Summary:                                                                                               
*    This program will display the monthly budget data                                                   
*                                                                                                        
*    Estimated:  0.0 hrs                                                                                 
*    Actual:     0.0 hrs                                                                                 
*      The most difficult of the assignment was getting the correct spacing                              
*      and formatting.                                                                                   
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************                                  
 * This function will output the monthly budget data in the requested                                    
 * format.                                                                                               
 ***********************************************************************/
int main()
{
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	// first row - headers                                                                                
	cout << "\t" << setw(13) << left << "Item"
		  << setw(2) << " "
		  << setw(10) << left <<  "Projected\n";
	// second row - divider line                                                                          
	cout << "\t=============  ==========\n";
	// third row - income                                                                                 
	cout << "\t" << setw(13) << left << "Income"
		  << setw(3) << right << " $"
		  << setw(9) << right << 1000.00
		  << endl;
	// fourth row - taxes                                                                                 
	cout << "\t" << setw(13) << left << "Taxes"
		  << setw(3) << right << " $"
		  << setw(9) << right << 100.00
		  << endl;
	// fifth row - tithing                                                                                
	cout << "\t" << setw(13) << left << "Tithing"
	     << setw(3) << right << " $"
		 << setw(9) << right << 100.00
		 << endl;
	// sixth row - living                                                                                 
    cout << "\t" << setw(13) << left << "Living"
 	 	 << setw(3) << right << " $"
		 << setw(9) << right << 650.00
		 << endl;
	// seventh row - other                                                                                
	cout << "\t" << setw(13) << left << "Other"
		 << setw(3) << right << " $"
		 << setw(9) << right << 90.00
		 << endl;
	// eighth row - divider line                                                                          
	cout << "\t=============  ==========\n";
	// ninth row - delta                                                                                  
	cout << "\t" << setw(13) << left << "Delta"
		 << setw(3) << right << " $"
		 << setw(9) << right << 60.00
		 << endl;
		 return 0;
		}

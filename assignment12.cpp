/***********************************************************************                                 
* Program:                                                                                               
*    Assignment 12, Input & Variables                                                                    
*    Brother Falin, CS124                                                                                
* Author:                                                                                                
*    Joseph Walker                                                                                       
* Summary:                                                                                               
*    This program will receive the user's monthly income, store it in a                                  
*    variable and then print it again in the console.                                                    
*                                                                                                        
*    Estimated:  0.75 hrs                                                                                
*    Actual:     0.0 hrs                                                                                 
*      Please describe briefly what was the most difficult part.                                         
************************************************************************/
#include <iomanip>
#include <iostream>
using namespace std;

/**********************************************************************                                  
 * The main function will create a variable for the users monthly income,                                
 * prompt the user to enter their income, and then print it on the next line                             
 ***********************************************************************/
int main()
{
	float income;
	cout << "\tYour monthly income: ";
	cin  >> income;
	cout << fixed;
	cout << setprecision(2);
	cout << "Your income is: $"
		  << setw(9) << right << income
		  << endl;
	return 0;
}


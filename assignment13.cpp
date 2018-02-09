/***********************************************************************                                 
* Program:                                                                                               
*    Assignment 13, Expressions
*    Brother Falin, CS124        
* Author:                                                                                                
*    Joseph Walker                                                                                           
* Summary:                                                                                               
*    This Program will receive a measurement in Fahrenheit and then it
*    will convert the measurement to Celsius rounded to an integer.
*    
*                                                                                                        
*    Estimated:  0.75 hrs                                                                                 
*    Actual:     0.0 hrs                                                                                 
*      Please describe briefly what was the most difficult part.                                         
************************************************************************/
#include <iomanip>
#include <iostream>
using namespace std;

/**********************************************************************                                  
* Add text here to describe what the function "main" does. Also don't forget                            
* to fill this out with meaningful text or YOU WILL LOSE POINTS.                                        
 ***********************************************************************/
int main()
{
	int fahrenheit;
	cout << "Please enter a temperature in Fahrenheit: ";
	cin  >> fahrenheit;
	cout << fixed;
	cout << setprecision(0);
	float celsius = 5.0 / 9.0 * ((float) fahrenheit - 32);
	cout << "Celsius: "
		 << celsius
		 << endl;
	return 0;
}

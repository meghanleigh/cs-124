/***********************************************************************
* Program:
*    Team Project 03, Missile Defense
*    Brother Falin, CS124
* Author:
* 
* Summary:
*    Enter a brief description of your program here!  Please note that if
*    you do not take the time to fill out this block, YOU WILL LOSE POINTS.
*    Before you begin working, estimate the time you think it will
*    take you to do the assignment and include it in this header block.
*    Before you submit the assignment include the actual time it took.
*
*    Estimated:  0.0 hrs
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * Get Missile Distance
 * Prompts user for distance in Kilometers.
 ***********************************************************************/
float getMissileDistance()
{
	float km;
	cout << "\tEnter the distance of the missile: ";
	cin >> km;
	return km;
}

/**********************************************************************
 * Convert Kilometers To Miles
 * converts distance in kilometers to miles.
 ***********************************************************************/
float convertKilometersToMiles(float km) 
{
	float miles = km * 0.621371;
	return miles;
}

/**********************************************************************
 * Should Fire Missile
 * Will determine if the missile is in firing range.
 ***********************************************************************/
bool shouldFireMissile(float distance)
{
	return (distance < 30);
}

/**********************************************************************
 * Main
 * Main will receives missile distance and evaluates weather or not to 
 * fire the missile.
 ***********************************************************************/
int main()
{
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	
	cout << "Super Secret Missile Defense Program\n\n";
	float km = getMissileDistance();
	float miles = convertKilometersToMiles(km);
	
	if (shouldFireMissile(miles))
	{
		cout << "\tDistance is " << miles << " miles, fire!";
	}
	else {
		cout << "\tDistnace is " << miles << " miles, hold your fire.";
	}
	
	return 0;
}

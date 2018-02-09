/***********************************************************************
* Program:
*    Assignment 21, Debugging
*    Brother Falin, CS124
* Author:
*    Joseph Walker
* Summary:
*    This Program will calculate how much Sue is spending on her car
*    all of the functions are currently stub functions.
*
*    Estimated:  0.0 hrs
*    Actual:     0.0 hrs
*
************************************************************************/

#include <iostream>
using namespace std;

getPeriodicCost();
getUsageCost();
display();

/**********************************************************************
 * main
 * stub version to find how much Sue spends on her car
 ***********************************************************************/
int main()
{
  getPeriodicCost();
  getUsageCost();
  display();
	return 0;
}

float getPeriodicCost() {
  float devalue = promptDevalue();
  float insurance = promptInsurance();
  float parking = promptParking();

  return 0.00;
}

float promptDevalue() {
  return 0.00;
}

float promptInsurance() {
  return 0.00;
}

float promptParking() {
  return 0.00;
}

float getUsageCost() {
  float mileage = promptMileage();
  float gas = promptGas();
  float repairs = promptRepairs();
  float tires = promptTires();
  return 0.00;
}

float promptMileage() {
  return 0.00;
}

float promptGas() {
  return 0.00;
}

float promptRepairs() {
  return 0.00;
}

float promptTires() {
  return 0.00;
}

void display() {
  cout << "Success\n";
}


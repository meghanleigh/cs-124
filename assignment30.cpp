/***********************************************************************
* Program:
*    Assignment 30, Array Syntax
*    Brother Falin, CS124
* Author:
*    Joseph Walker
* Summary:
*    This program will prompt the user for 10 grades and then find and
*    display the average of the 10 grades given.
*
*    Estimated:  0.75 hrs
*    Actual:     0.25 hrs
*      Learning how to pass an array to a function and its behavior
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * Get Grades
 * Prompt the user for 10 grades, one at a time.
 ***********************************************************************/
void getGrades(int grades[])
{

  // prompt the user for the grade and store it in the array
  for (int i = 0; i < 10; i++)
    {
      int gradeNumber = i + 1;
      cout << "Grade " << gradeNumber << ": ";
      cin >> grades[i];
    }
}

/**********************************************************************
 * Get Average
 * Calculate the Average of the 10 grades given by the user.
 ***********************************************************************/
int getAverage(int grades[])
{
  int average;
  int sum;
  // get the sum of the array
  for (int i = 0; i < 10; i++)
    {
      sum += grades[i];
    }
    
  // calculate the average  
  average = sum / 10;

  return average;
}

/**********************************************************************
 * main
 * initialize the grades array and call the getGrades function and the
 * getAverage function. It will then print the average.
 ***********************************************************************/
int main()
{
  int grades[10];
  getGrades(grades);

  int average = getAverage(grades);

  // display the average
  cout << "Average Grade: " << average << "%" << endl;
	return 0;
}

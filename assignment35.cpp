/***********************************************************************
* Program:
*    Assignment 35, Advanced Conditionals
*    Brother Falin, CS124
* Author:
*    Joseph Walker
* Summary:
*    This program will prompt the user for their score and convert it
*    to the proper letter grade and sign.
*    
*
*    Estimated:  0.75 hrs
*    Actual:     0.5 hrs
*      getting the conditions to work right
************************************************************************/

#include <iostream>
using namespace std;

char computeLetterGrade(int numGrade);
char computeGradeSign(int numGrade);

/**********************************************************************
 * main
 * This function will prompt the user for a number graded then display
 * the letter grade
 ***********************************************************************/
int main()
{
  int numGrade;
  cout << "Enter number grade: ";
  cin >> numGrade;
  
  char letterGrade = computeLetterGrade(numGrade);
  char sign = computeGradeSign(numGrade);
  
  cout << numGrade << "% is " << letterGrade << sign;
  if (sign != '\n')
  {
    cout << endl;
  }
	return 0;
}

char computeLetterGrade(int numGrade)
{
  if (numGrade <= 100 && numGrade >= 90)
  {
    return 'A';
  }
  else if (numGrade < 90 && numGrade >= 80)
  {
    return 'B';
  }
  else if (numGrade < 80 && numGrade >= 70)
  {
    return 'C';
  }
  else if (numGrade < 70 && numGrade >= 60)
  {
    return 'D';
  }
  else
  {
    return 'F';
  }
}

char computeGradeSign(int numGrade)
{
  if ((numGrade >= 60 && numGrade < 65)
  || (numGrade >= 70 && numGrade < 75)
  || (numGrade >= 80 && numGrade < 85)
  || (numGrade >= 90 && numGrade < 95))
    {
      return '-';
    }
  else if ((numGrade <= 70 && numGrade > 65)
  || (numGrade <= 80 && numGrade > 75)
  || (numGrade <= 90 && numGrade > 85))
    {
      return '+';
    }
  else
    {
      return '\n';
    }
}

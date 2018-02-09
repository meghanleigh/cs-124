/***********************************************************************                                 
* Program:                                                                                               
*    Assignment 14, Matthew 18:21-22                                                                     
*    Brother Falin, CS124                              
* Author:                                                                                                
*    Joseph Walker                                                                                       
* Summary:                                                                                               
*    This program will address Peter's question to the Lord in                                           
*    Matthew 18:21-22                                                                                    
*                                                                                                        
*    Estimated:  0.75 hrs                                                                                 
*    Actual:     0.30 hrs                                                                                 
*      The most difficult part was learning how to return the right value
*	   for each function.                                  
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
* Question Peter
* Display Peter's question to the Lord.
***********************************************************************/
int questionPeter()
{
	// display the Peter's question
	cout<< "Lord, How oft shall my brother sin against me, and I forgive him?\n"
		<< "Till seven times?"
		<< endl;
	return 0;
}
/**********************************************************************
* Response Lord
* Calculate the Lord's response to Peter.
***********************************************************************/
int responseLord()
{
	// dislplay the answer to Peter's question
	float answerLord = 70 * 7;
	return answerLord;
	
}
/**********************************************************************                                  
* You are not allowed to change MAIN in any way; just implement the two                                  
* functions: questionPeter() and responseLord()                                                          
***********************************************************************/
int main()
{
	// ask Peter's question                                                                               
	questionPeter();

	// the first part of the Lord's response                                                              
	cout << "Jesus saith unto him, I say not unto thee, Until seven\n";
	cout << "times: but, Until " << responseLord() << ".\n";

	return 0;
}


/*
Name: Sean McKay, Jeremy Joseph Klotz, Rebecca Tran
MadID: mckaysm, klotzjj, tranr5
Student Number: 1423885, 1426853, 1425611	
Description: calculating an expression given by user
*/
#ifndef __ADD_H_		// header guard
#define __ADD_H_		// header guard
#include <string>		// necessary for function of code
#include "ArithmeticExpression.h"	// include the header file of the class this one inherits

using namespace std;				// using standard namespace for normal operation
using std::string;					// using std::string for string manipulation for the class

class Addition: public ArithmeticExpression{		// Addition extends from ArithmeticExpression
public:				// proceeding variables / methods are public
	Addition();		// define Addition constructor to be used throughout the program
	virtual ~Addition();	// define Addition destructor to be used throughout the program
	void print();			// define the print method with void value 
	string evaluate();		// define evaluate() as a function that returns a string
	void increment();		//method for incrementing expression
private:			// proceeding variables  are private


};

#endif						
// end the if not define section

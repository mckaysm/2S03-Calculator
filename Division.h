/*
Name: Sean McKay, Jeremy Joseph Klotz, Rebecca Tran
MadID: mckaysm, klotzjj, tranr5
Student Number: 1423885, 1426853, 1425611	
Description: calculating an expression given by user
*/

#ifndef __DIVISION_H_		// header guard
#define __DIVISION_H_		// header guard
#include <string>			// necessary for function of code
#include "ArithmeticExpression.h"	// include the header file of the class we extend

using namespace std;		// using standard namespace for standard operations
using std::string;			// using to allow operations as string objects

class Division: public ArithmeticExpression{	// Division extends from ArithmeticExpression 
public:		// proceeding variables / methods are public
	Division();	// Division constructor
	virtual ~Division();	// Division destructor
	string evaluate();		// initialize evaluate as a method that returns a string
	void print();			// initialize print as a method that has void return value 
	void increment();		//method for incrementing expression
private:	// proceeding variables are private


};
#endif
// end header 

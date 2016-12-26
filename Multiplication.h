/*
Name: Sean McKay, Jeremy Joseph Klotz, Rebecca Tran
MadID: mckaysm, klotzjj, tranr5
Student Number: 1423885, 1426853, 1425611	
Description: calculating an expression given by user
*/

#ifndef __MULTIPLICATION_H_		// header guard
#define __MULTIPLICATION_H_		// header guard
#include <string>		// necessary for function of code
#include "ArithmeticExpression.h"	// include the header file of the class we extend from (Arithmetic Expression)

using namespace std;		// necessary for standard operations
using std::string;			// necessary for operation with string objects

class Multiplication: public ArithmeticExpression{	// Multiplication extends / inherits from ArithmeticExpression
public:						// the proceeding variables / methods are public
	Multiplication();		// Multiplication constructor initialization
	virtual ~Multiplication();	// initialize destructor of multiplication 
	string evaluate();		//	initialize evaluate as a method that returns a string
	void print();			// initialize print as a method that has void return value
	void increment();		//method for incrementing expression
private:					// proceedinng variables are private


};

#endif
// end header guard 

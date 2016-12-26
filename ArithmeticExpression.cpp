/*
Name: Sean McKay, Jeremy Joseph Klotz, Rebecca Tran
MadID: mckaysm, klotzjj, tranr5
Student Number: 1423885, 1426853, 1425611	
Description: calculating an expression given by user
*/

#include "Expression.h"				// Arithmetic expression inherits / extends from Expression
#include "ArithmeticExpression.h"	// include the header file that declares variables / methods to be implemented
#include <string>					// include for string operations
#include <sstream>					// include for string operations
#include <iostream>					// include for input and output operations
#include <iomanip>					// include for set precision 
#include <stdlib.h>					// include the standard library 

using namespace std;				// using standard namespace for standard operations 

ArithmeticExpression::ArithmeticExpression() {		// constructor for ArithmeticExpression
	left = NULL;		// default action set left to NULL
	right = NULL;		// default action set right side to NULL
}
ArithmeticExpression::~ArithmeticExpression() {		// destructor for ArithmeticExpression
	delete left;		// delete the left hand side
	delete right;		// delete the right hand side of ArithmeticExpression
}
float ArithmeticExpression::convert(string s){		// convert final expression to float
	float f;			// define f as a float
	f = atof(s.c_str());	// convert string to a decimal number
	return (float) f;		// return  f as a float

}



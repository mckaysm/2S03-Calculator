/*
Name: Sean McKay, Jeremy Joseph Klotz, Rebecca Tran
MadID: mckaysm, klotzjj, tranr5
Student Number: 1423885, 1426853, 1425611	
Description: calculating an expression given by user
*/
#include <sstream>					// include for program to operate
#include <iostream>					// include for program to operate
#include "Subtraction.h"			// include header file of the class
#include "ArithmeticExpression.h"	// include header file of class Subtraction extends from (ArithmeticExpression)
#include <string>					// include for program to operate
#include <stdlib.h>					// include for program to operate

using namespace std;				// include standard namespace for compiler to recognize standard operations
using std::string;					// needed for operation string objects
Subtraction::Subtraction() {		// Subtraction constructor

}
Subtraction::~Subtraction() {		// Subtraction destructor

}
string Subtraction::evaluate(){			// evaluate method on Subtraction object
	string l;	// initialize the left side of the expression as a string for when we split at the operator
	string r;	// initialize the right side of the expression as a string for when we split
	double a;	// initialize a ( or the left side of the expression ) as a double, will make "left" convert to double a
	double b;	// initialize b ( or the right side of the expression ) as a double, will make "right" conver to double b
	double subtraction;	// initialize subtraction as a double
	l = left->evaluate();				// recursively call evaluate on the left hand 
	r = right->evaluate();				// recursively call evaluate on right hand side
	a = atof((l).c_str());				// convert left hand side to a double
	b = atof((r).c_str());				// convert right hand side to a double
	subtraction = a - b;				// store a - b into subtraction
	ostringstream output; 				// initialize output as an output string stream value
	output << subtraction;				// create an object called output that is of output string stream that holds subtraction
	return output.str();				// return  the subtraction as a string

}

void Subtraction::print(){
	cout << "(";	// print the opening bracket
	left->print();	// recursively call print on left hand side
	cout << " - "; 	// print the subtraction operator
	right->print();	// recursively call print on the right hand side
	cout << ")";	// print the closing bracket of the expression
}

void Subtraction::increment(){
	left -> increment();	//Recursively increment the left side of the expression
	right -> increment();	//Recursively increment the right side of the expression
}

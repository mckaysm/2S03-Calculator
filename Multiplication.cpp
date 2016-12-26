/*
Name: Sean McKay, Jeremy Joseph Klotz, Rebecca Tran
MadID: mckaysm, klotzjj, tranr5
Student Number: 1423885, 1426853, 1425611	
Description: calculating an expression given by user
*/

#include <sstream>				// include for program to operate
#include <iostream>				// include for program to operate
#include "Multiplication.h"		// include header file
#include "ArithmeticExpression.h"	// include header file of class Multiplication inherits from
#include <string>				// include for program to operate
#include <stdlib.h>				// include for program to operate

using namespace std;
using std::string;
Multiplication::Multiplication() {		// Multiplication constructor

}
Multiplication::~Multiplication() {		// Multiplication destructor

}
string Multiplication::evaluate(){
	string l;				// string for left hand side
	string r;				// string for right hand side
	double a;				// initialize a double for converting left hand side
	double b;				// initialize a duoble for converting right hand side
	double multiply;		// initialize multiply as a double for storing multiplication
	l = left->evaluate();			// recursively call evaluate on left hand side
	r = right->evaluate();			// recursively call evaluate on right hand side
	a = atof((l).c_str());			// convert left hand side to a double
	b = atof((r).c_str());			// convert right hand side to a double
	multiply = a * b;				// store a * b into multiply
	ostringstream output; 			// create output string stream object
	output << multiply;				// create an object called output that is of output string stream that holds addition
	return output.str();			// return  the multiplication as a string

}

void Multiplication::print(){
	cout << "(";		// print opening bracket for expression
	left->print();		// recursively call print on the left hand side of the expression
	cout << " * ";		// print out the multiplication operator
	right->print();		// recursively call print on the right hand side of the expression
	cout << ")";		// print out a closing bracket
}

void Multiplication::increment(){
	left -> increment();	//Recursively increment the left side of the expression
	right -> increment();	//Recursively increment the right side of the expression
}


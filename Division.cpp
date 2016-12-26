/*
Name: Sean McKay, Jeremy Joseph Klotz, Rebecca Tran
MadID: mckaysm, klotzjj, tranr5
Student Number: 1423885, 1426853, 1425611	
Description: calculating an expression given by user
*/

#include <sstream>			// include for program to operate
#include <iostream>			// include for program to operate
#include "Division.h"		// include for program to operate
#include "ArithmeticExpression.h" // include for program to operate
#include <string>			// include for program to operate
#include <stdlib.h>			// include for program to operate

using namespace std;		// using namespace std for compiler to recognize standard operations
using std::string;			// necessarry for operating with string objects 
Division::Division() {		// Divison Constructor

}
Division::~Division() {		// Division destructor

}
string Division::evaluate(){	// Evaluate method for division
	double a;				// declare double for conversion
	double b;				// declare double for conversion
	string l;				// declare string for left hand side
	string r;				// declare string for right hand side
	double divide;			// declare divide as a double
	l = left -> evaluate();		// recursively call evaluate on left hand side
	r = right -> evaluate();	// recursive call evaluate on right hand side
	a  = atof(l.c_str());		// convert left hand side to a double
	b = atof(r.c_str());		// conver right hand side to a double
	divide = a / b;				// store a / b into divide
	ostringstream output; 		// create an ouutput string stream object called output
	output << divide;		// create an object called output that is of output string stream that holds addition
	return output.str();	// return  the addition as a string
}

void Division::print(){
	cout << "(";	// print opening bracket
	left->print();	// recursively call print on the lefthand side
	cout << " / "; // print operator
	right->print();	// recursively call print on the right hand side
	cout << ")";	// print closing bracket
}

void Division::increment(){
	left -> increment();	//Recursively increment the left side of the expression
	right -> increment();	//Recursively increment the right side of the expression
}

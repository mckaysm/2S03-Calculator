/*
Name: Sean McKay, Jeremy Joseph Klotz, Rebecca Tran
MadID: mckaysm, klotzjj, tranr5
Student Number: 1423885, 1426853, 1425611	
Description: calculating an expression given by user
*/

#include <sstream>					// needed for working with strings (atof)
#include <iostream>					// needed package for using input / output
#include "Addition.h"				// we must include the header file of the cpp file
#include "ArithmeticExpression.h"	// we must include the header file of the cpp file in which Addition inherits from
#include <string>					// needed package to work with strings
#include <stdlib.h>					// included standard library to enable program to run properly

using namespace std;				// must include standard namespace
using std::string;					// using std::string for string operations when the class will be called

Addition::Addition() {		// constructor of Addition

}

Addition::~Addition() {		// destructor of Addition

}

string Addition::evaluate(){		// declare evaluate method of Addition
	string l;		// define a string for lefthand side of expression
	string r;		// define a string for righthand side of expression
	double a;		// define a double for converting
	double b;		// define a double for converting
	double addition;	// define a double for addition of lefthand and righthand side
	l = left->evaluate();			// recursively call evaluate on left hand side of expression
	r = right->evaluate();			// recursively call evaluate on right hand side of expression
	a = atof((l).c_str());			// convert left hand evaluate to a double / float
	b = atof((r).c_str());			// conver left hand evaluate to a double / float 
	addition = a + b;				// store a + b into addition
	ostringstream output;			// create an output string steam object called output
	output << addition;	            // output holds addition
	return output.str();			// return output object as a string. 
}

void Addition::print(){				// declare print method of Addition
	cout << "(";					// print an opening bracket 
	left->print();					// recursively call print on left hand side
	cout << " + "; 					// print the addition operator
	right->print();					// recursively call print on the right hand side
	cout << ")";					// print a closing bracket to close the expression.
}

void Addition::increment(){
	left -> increment();	//Recursively increment the left side of the expression
	right -> increment();	//Recursively increment the right side of the expression
}


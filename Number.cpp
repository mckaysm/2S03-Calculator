/*
Name: Sean McKay, Jeremy Joseph Klotz, Rebecca Tran
MadID: mckaysm, klotzjj, tranr5
Student Number: 1423885, 1426853, 1425611	
Description: calculating an expression given by user
*/

//importing
#include <sstream>	//included for use of sstream
#include <iostream>	//included for use of iostream
#include "Number.h"	//including header file of Number
#include "ArithmeticExpression.h"	//including header file of ArithExpr
#include <string>	//for use of string
#include <stdlib.h>	//included for use of standard library

using namespace std;	//so we don't need to type std::
using std::string;	//necessary for string objects operations

Number::Number() {	//Constructor
	isNegative = false;
}	//closing bracket

Number::~Number() {	//destructor
}	//closing bracket

string Number::evaluate() {	//Creating evaluate as a function of Number
	return number;	//return
}	//closing bracket

void Number::print() {	//Creating print as a function of Number
	cout << number;	//print out number
}	//closing bracket

void Number::increment() {
	double temp;	//Temporary variable for converting from string
	ostringstream s;	//Temporary string for storing double
	if (isNegative) {	//Special case for negative numbers
		temp =atof(number.c_str());	//Converting from string to double
		temp += 2;	//Incrementing by 2 (so  (-5) == (0 - 5) becomes (2 - 6) == (-4))
		 s << temp; //Storing new value of number
		 number = s.str();	//setting new value of number
	}
	else {
		temp =atof(number.c_str());	//Converting from string to double
		temp += 1;	//Incrementing by 1
		s << temp;	// Storing new value of number
		number = s.str();	//setting new value of number
	}
}

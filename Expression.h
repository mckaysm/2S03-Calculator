/*
Name: Sean McKay, Jeremy Joseph Klotz, Rebecca Tran
MadID: mckaysm, klotzjj, tranr5
Student Number: 1423885, 1426853, 1425611	
Description: calculating an expression given by user
*/

#ifndef __EXPRESSION_H_		// header guard
#define __EXPRESSION_H_		// header guard
#include <string>			// include for string operations
#include <iostream>			// include for input / output operations

using namespace std;		// using namespace for standard operations
using std::string;			// using for string object operations

class Expression {			// define what is inside of class Expression
public:
	Expression();			// define Expression constructor
	virtual ~Expression() {};	// define expression destructor for further use 
	virtual string evaluate()=0;	// define evaluate as a method that returns a string for further use
	virtual float convert(string s)=0;	// define convert as a method that takes in a string as input and returns a float for further use
	virtual void print()=0;		// define a method called print that will have void return value
	virtual void increment()=0;

};

#endif
// end header guard

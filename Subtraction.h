/*
Name: Sean McKay, Jeremy Joseph Klotz, Rebecca Tran
MadID: mckaysm, klotzjj, tranr5
Student Number: 1423885, 1426853, 1425611	
Description: calculating an expression given by user
*/

#ifndef __SUBTRACTION_H_		// header guard
#define __SUBTRACTION_H_		// header guard
#include <string>				// necessary for function of code since working with string
#include "ArithmeticExpression.h"	//including headerfile of ArithmeticExpression

using namespace std;	//so we don't need std::
using std::string;	//necessary for string objects operation 

class Subtraction: public ArithmeticExpression {	//class Subtraction is public and extends from ArithmeticExpression
public:	
	Subtraction();	// initialize object Subtraction of given expression as a string
	virtual ~Subtraction(); //destructor
	string evaluate();	// create evaluate as string type object
	void print();	//initializing print as a method that returns a void value
	void increment();
private:


};	//closing bracket

#endif
//end of header guard

/*
Name: Sean McKay, Jeremy Joseph Klotz, Rebecca Tran
MadID: mckaysm, klotzjj, tranr5
Student Number: 1423885, 1426853, 1425611	
Description: calculating an expression given by user
*/

//importing	
#ifndef __NUMBER_H_	//header guard
#define __NUMBER_H_	//header guard
#include <string>	//included for use of string
#include <iostream>	//included for use of iostream
#include "ArithmeticExpression.h"	//including the arithexpr header file

using namespace std;	//so we don't need std::
using std::string;	//necessary for string objects operation 

class Number: public ArithmeticExpression {	//class Number is public and extends from ArithmeticExpression
public:	//declaring all below as a public
	Number();	//constructor
	virtual ~Number();	//destructor
	string evaluate();	//declaring 
	void print();	//initializing print as a method that returns a void value
	void increment();	//method for incrementing expression
	string number;	//declaring number
	bool isNegative;	//For incrementing negative numbers

};	//closing bracket	

#endif
//end of header guard

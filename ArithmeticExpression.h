/*
Name: Sean McKay, Jeremy Joseph Klotz, Rebecca Tran
MadID: mckaysm, klotzjj, tranr5
Student Number: 1423885, 1426853, 1425611	
Description: calculating an expression given by user
*/

#ifndef __ArithmeticExpression__		// Header guard
#define __ArithmeticExpression__		// Header guard
#include "Expression.h"					// must include header file of class we extend from
#include <string>						// include string for string operations


using namespace std;					// using standard namespace for compiler to recognize standard operations
using std::string;						// using this to allow ArithmeticExpression to work with strings


class ArithmeticExpression : public Expression{	// arithmetic expression extends from Expression
public:								// proceeding variables are public 
	ArithmeticExpression();			// initialize constructor of ArithmeticExpression
	virtual ~ArithmeticExpression();// initialize destructor of ArithmeticExpression
	virtual string evaluate()=0;	// declare evaluate as a string method to be later defined
	virtual void print()=0;			// declare print as a void method to be later defined
	virtual void increment()=0;
	float convert(string s);		// declare convert as a function / method that returns a float and takes in a string
	Expression *left;				// declare the left hand side of Arithmetic expression of object "Expression"
	Expression *right;				// declare the right hand side of Arithmetic expression of object "Expression"

private:		// proceeding variables are private
	string expression;	// declare expression as a string

};

#endif
// end header guard

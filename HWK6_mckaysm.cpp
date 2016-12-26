/*
Name: Sean McKay, Jeremy Joseph Klotz, Rebecca Tran
MadID: mckaysm, klotzjj, tranr5
Student Number: 1423885, 1426853, 1425611	
Description: calculating an expression given by user
*/

//importing
#include <iostream>	//included for use of iostream
#include <math.h>	//included for math functions
#include <string>	//used to use string
#include <algorithm>	//included for use of algorithm 
#include <iomanip>	//necessary for use of setprecision
#include "Subtraction.h"	//including header file for sub
#include "Addition.h"	//including header file for add
#include "Multiplication.h"	//including header file for mult
#include "Division.h"	//including header file for div
#include "Number.h"	//including header file for num
using namespace std;	//so we don't need to do std::

bool isOpMD(char c) {	//boolean check
	if (c == '*' or c == '/') {	//if statement, if char is a * or /
		return true;	//bool = T
	}	//closing bracket
	else {	//else statement
		return false;	//if char is neither a * or /, set bool to F
	}	//closing bracket
}	//closing bracket

bool isOpAS(char c) {	//boolean check
	if (c == '+' or c == '-') {	//if staement, if char is a + or -
		return true;	//set bool = T
	}	//closing bracket
	else {	//else statement
		return false;	//set bool = F if not + or -
	}	//closing bracket
}	//closing bracket

bool validExpression(string expression) {
	/* Returns true if the expression is valid
	 * One operator for two values,
	 * equal number of opening and closing brackets
	 */
	int len = expression.length();	//Expression length
	int oBrack = 0, cBrack = 0, nums = 0, ops = 0, uops = 0;	//Valid characters
	int i = 0;	//Counter
	char lastchar = 0;	//Value of character at index i - 1
	char lastOpOrNum = 0; //last character that isn't a brackets or space

	while (i < len) {	//Loop over expression
		char c = expression[i];	//Get character at index i



		if (isspace(c)) {	//If the character is a whitespace
			//Do nothing
		}	//else to handle multiple negatives
		else if (c == '(') {	//else statement, if the char is an '('
			oBrack ++;	//increment oBrackets
			lastchar = c;	//set lastchar to the current char
		}	//closing bracket
		else if (c == ')') {	//else statement, if char is ')'	'
			cBrack ++;	//increment cBrack
			lastchar = c;	//set lastchar to current char

		}	//closing bracket
		else if (isdigit(c)) {	//else statement, if char is a digit
			if (i >= 1 and isdigit(expression[i-1])) {	//if statement, if i greater than & equal to 1, and the prev char is also a digit
				//do nothing
			}	//closing bracket
			else if (i >= 2 and (isspace(expression[i - 1]) and isdigit(lastOpOrNum))) {	//else statement, if i greater than 2, the last char is a whitespace and the seclast char is a digit
				cout << "Expression not well formed" << endl;	//print out message
				return false;	//return false, not valid expression
			}	//closing bracket
			else {	//else statement
				nums ++;	//increment nums

			}	//closing else 
			lastchar = c;	//set lastchar to c
			lastOpOrNum = c; //set lastOpOrNum to c
		}	//closing bracket
		else if (c == '*' or c == '/' or c == '+' or c == '-') {	//else statement, if c is equal to an operator
			if (c == '-' and (isOpMD(lastOpOrNum) or isOpAS(lastOpOrNum) or lastOpOrNum == 0) and lastchar == '(') {	//For unary minus
				uops++;	//Increment unary op count
			}
			else if (isOpMD(lastOpOrNum) or isOpAS(lastOpOrNum)) {
				cout << "Expression not well formed" << endl;	//print out message
				return false;	//not valid expression
			}
			else {
				ops ++;	//increment ops
			}
			lastchar = c;	//lastchar equal to c
			lastOpOrNum = c;	//set lastOpOrNum to c

		}	//closing bracket
		else {	//else statement
			cout << "Expression not well formed" << endl;	//print out message
			return false;	//return false, change boolean statement
		}	//closing bracket
 		i ++;	//increment i
	}	//closing bracket

	if (oBrack != cBrack) {	//if statement, if the number of oBrack DNE to the number of cBrack
		cout << "Expression not well formed" << endl;	//print out message if above is T
		return false;	//set boolean to false, not valid expression
	}	//closing bracket
	if (nums != ops + 1) {	//if statement, if nums DNE ops+1
		cout << "Expression not well formed"<< endl;	//print out message if above is T
		return false;	//set bool to F, not valid expression
	}	//closing bracket
	return true;	//return True if the rest pass
}	//closing bracket

string removeWhitespace(string expression) {	//function to remove whitespeace
	string:: iterator end_pos = std::remove(expression.begin(), expression.end(), ' ');	//go through and find whitespace
	expression.erase(end_pos, expression.end());	//remove whitespace
	return expression;	//return expression
}	//closing bracket

string simplify(string expression) {	//function to simplify expression
	int len = expression.length();	//set len equal to the length of the expression
	int ops = 0;	//declaring variable ops to 0
	int bracks = 0;	//declaring variable bracks to 0

	for (int i = 0; i < len; ++i) {	//for loop, if i equal to 0, i less than the length, increment i
		if (expression[i] == '(') {	//if the current position in the expression is a '(' 
			bracks ++;	//increment bracks
		}	//closing bracket
		if  (expression[i] == ')') {	//if statement, if the current position in expr is ')'
			bracks --;	//decrement bracks
		}	//closing bracket
		if( bracks == 0 and (isOpMD(expression[i]) or isOpAS(expression[i]))) {	//if bracks equals 0, and there is a * / or + - at current position in expr
			ops++;	//increment ops
		}	//closing bracket
	}	//closing bracket
	if (expression[0] == '(' and expression[len - 1]== ')' and ops == 0) {	//if statement, if first element in expr is a '(' and the last element is a ')' and ops equals 0
		expression = expression.substr(1, len - 2);	//set expression equal to whatever is inside ( ) of substring, excludes ( )
	}	//closing bracket
	return expression;	//returning function expression
}	//closing bracket

Expression* splitInTwo(string expression) {	//spliting expression function
	int len = expression.length();	//declaring len equal to the length of the expression
	int i = len - 1;	//i is equal to the length minus 1
	string l = "";	//declaring variable l to an empty string
	string r = "";	//declaring variable r to an empty string
	char op;	//declaring variable ops as char 
	int bracks = 0;	//declaring variable bracks to 0
	int digits = 0;	//declaring variable digits to 0 
	int ops;	//declaring variable ops

	//Look for (+) and (-) operators
	while (i >= 0) {	//while loop, while i is greater than or equal to 0
		char c = expression[i];	//set c equal to the current position in expression

		if (c == ')') {	//if statement, if c is equal to ')'
			bracks ++;	//increment bracks
		}	//closing bracket
		else if (c == '(') {	//else statement, if c is equal to '('
			bracks--;	//decrement bracks
		}	//closing bracket
		else if (isOpAS(c)) {	//else statement, if c is an + or -
			ops++;	//increment ops
			if (bracks == 0) {	//if statement, if bracks is equal to 0
				op = c;	//set op to c
				if (i > 0) {	//if statement, if above is true, check if i is greater than 0 
					l = expression.substr(0, i);	//if above is T, get the substring from 0 to current position, set to l
					r = expression.substr(i + 1, len);	//get substring from one after current position to the length of the expr, set to r
				}	//closing bracket

				if (op == '+') {	//if op is a '+'
					Addition* exp = new Addition();	//Making a pointer of type Addition, of new Addition object
					exp->left = splitInTwo(simplify(l));	//take pointer exp, evaluate left hand side and simplify
					exp->right = splitInTwo(simplify(r));	//take pointer exp, evaluate right hand side and simplify
					return exp;	//return exp 
				}	//closing bracket
				else {	//else statement
					if (i > 0) {	//if statement, if i is greater than 0
						Subtraction* exp = new Subtraction();	//Making a pointer of type Subtraction, of new Subtraction object
						exp->left = splitInTwo(simplify(l));	//take pointer exp, evaluate left side and simplify
						exp->right = splitInTwo(simplify(r));	//take pointer exp, evaluate right side and simplify
						return exp;	//return exp function
					}	//closing bracket
					else {	//else statement, i is not greater than 0 (dealing with neg numbers)
						Subtraction* exp = new Subtraction();	//Making a pointer of type Subtraction, of new Substraction object
						Number* exp2 = new Number();	//Make a pointer of type Number, of new Number object
						exp2->number = "0";	//take exp pointer, calls number and set it equal to the expr
						exp2->isNegative = true;
						exp->left = exp2;
						exp->right = splitInTwo(simplify(expression.substr(1, len)));	//pointer exp, split and simplify the rest of substr to equal 1 to the length of expr
						return exp;	//return exp 
					}	//closing bracket
				}	//closing bracket
			}	//closing bracket

			else {	//else statement

				// do nothing
			}	//closing bracket
		}	//closing bracket
		else if (isdigit(c)){	//else statement, if c is a digit
			digits++;	//increment digits
		}	//closing bracket
		i --;	//decrement i
	}	//closing bracket

	i = len - 1;	//set i to one less than the length

	//Look for (*) and (/) operators
	while (i >= 0) {	//while loop, if i is greater than or equal to 0
		char c = expression[i];	//set c to the current position in expr
		if (c == '(') {	//if statement, if c is equal to '('
			bracks ++;	//increment bracks
		}	//closing bracket
		else if (c == ')') {	//else statement, if c is equal to ')'
			bracks --;	//decrement bracks
		}	//closing bracket
		else if (isOpMD(c)) {	//else statement, if c is * or /
			ops++;	//increment ops
			if (bracks == 0) {	//if statement, if bracks is equal to 0
				op = c;	//set op to c
				l = expression.substr(0, i);	//set l to the substring from 0 to current position in expr
				r = expression.substr(i + 1, len);	//set r to the rest of the substring, one after the current position

				if (op == '*') {	//if op is a multiplication
					Multiplication* exp = new Multiplication();	//Make a pointer of type Multiplcation, of new Multiplication object
					exp->left = splitInTwo(simplify(l));	//take exp pointer, split it and simplify left side
					exp->right = splitInTwo(simplify(r));	//take exp pointer, split it and simplify right side
					return exp;	//return exp
				}	//closing bracket
				else {	//else statement
					Division* exp = new Division(); //Make a pointer of type Division, of new Division object
					exp->left = splitInTwo(simplify(l));	//take exp pointer, point to left side, split it and simplify
					exp->right = splitInTwo(simplify(r));	//take exp pointer, point to right side, split it and simplify 
					return exp;	//return exp 
				}	//closing bracket
			}	//closing bracket
			else {	//else statement

				// do nothing

			}	//closing bracket
		}	//closing bracket
		else if (isdigit(c)){	//else statement, if c is a digit
				digits++;	//increment digits if above is T
		}	//closing bracket

		i--;	//decrement i
	}	//closing bracket

	if (digits > 1) {	//if statement, if digits is greater than 1
		Number* exp = new Number();	//Make a pointer of type Number, of new Number object
		exp->number = expression;	//take exp pointer, calls number and set it equal to the expr
		return exp;	//return exp
	}	//closing bracket
	return NULL;	//return null
}	//closing bracket

int main() {	//main function
	string input;	//declaring variable input
	Expression* root = NULL;	//declaring root (top of the tree)
	string result;	//declaring variable result
	while (input != "#") {	//while loop, while the input is not an #
		cout << "Enter an expression:" << endl;	//print out message
		getline(cin, input);	//get input
		if (input == "#") {	//if the input is equal to a #
				cout << "Exiting" << endl;	//print out message
		}	//closing bracket
		else if (input == "@") {	//If input is a @
			if (root != NULL) {
				root->increment();	//Increment root
				result = root->evaluate();	//Evaluate the expression and store in result
				root->print();	//Print out the entire expression
				cout << " = " << fixed << setprecision(2) << root->convert(result) << endl;	//Formatting output to 2 decimals and converting result to a float
			}
			else {
				cout << "No previous expression to increment" << endl; //User needs to enter a valid input before using @
			}

		}
		else {	//else statement
			if (validExpression(input)) {	//if statment, if input is valid
				if (root != NULL) {
					delete root;	//deleting last value of root
				}
				input = simplify(removeWhitespace(input));	//input is now simplified, with removed whitespace
				root = splitInTwo(input);	//root is now the expression split
				result = root->evaluate();	//result is entire expression evaluated
				root->print();	//print out root
				cout << " = " << fixed << setprecision(2) << root->convert(result) <<  endl;	//formatting output, 2 decimals and converting result
			}	//closing bracket
		}	//closing bracket
	}	//closing bracket

	return 0;	//return 0
}	//closing bracket

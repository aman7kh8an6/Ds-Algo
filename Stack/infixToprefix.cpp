#include<iostream>
#include<stack>
using namespace std;

// reverse the string and convert thr opening to closing bracket nd viceversa.
// if operand
//      print
// if '('
//      push to stack
// if ')'
//      pop from stack and print until '(' is found
// if operator
//      pop from stack and print until an operator with less precedence is found

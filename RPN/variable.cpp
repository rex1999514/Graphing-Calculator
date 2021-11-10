#include "variable.h"

Variable::Variable():Token(VARIABLE)
{

}

//turn string to double
Variable::Variable(string s):Token(VARIABLE)
{
    _var = s;
}

//print the number
void Variable::print() const
{
    Token::print();
    cout << _var << endl;
}

string Variable::VAR() const
{
    return _var;
}


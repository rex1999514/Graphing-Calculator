#include "number.h"

Number::Number():Token(NUMBER)
{

}

//turn string to double
Number::Number(string s):Token(NUMBER)
{
    _num = stod(s);
}

Number::Number(double num):Token(NUMBER)
{
    _num = num;
}

//print the number
void Number::print() const
{
    Token::print();
    cout << _num << endl;
}

double Number::NUM() const
{
    return _num;
}

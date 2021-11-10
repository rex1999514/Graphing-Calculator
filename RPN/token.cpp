#include "token.h"

//This is the parent class for Operator, LPARENT, RPARENT and Number
Token::Token()
{

}

Token::Token(TOKEN type)
{
    _type = type;
}

Token::~Token()
{

}

void Token::print() const
{
    cout << "This is the print function for Token." << endl;
    cout << "My Token is " << _type << endl;
}

TOKEN Token::type() const
{
    return _type;
}

ostream& operator <<(ostream& outs, const Token& t)
{
    t.print();
    return outs;
}

ostream& operator <<(ostream& outs, const Token*& t)
{
    t->print();
    return outs;
}

#include "operator.h"

Operator::Operator():Token(OPERATOR)
{

}

//use precedence to distinguish the prioroty during calculation
Operator::Operator(string op):Token(OPERATOR)
{
    _op = op;
    if (op == "sin" || op == "cos" || op == "ln" || op == "tan" || op == "log" || op == "Max" || op == "Min")
    {
        _precedence = 3;
    }
    else if (op == "^")
    {
        _precedence = 2;
    }
    else if (op == "*" || op == "/")
    {
        _precedence = 1;
    }
    else if (op == "-")
    {
        _precedence = 0;
    }
    else if (op == "+")
    {
        _precedence = 0;
    }
}

int Operator::Prec() const
{
    return _precedence;
}

string Operator::OP() const
{
    return _op;
}

void Operator::print() const
{
    Token::print();
    cout << _op << endl;
}

//>= operator, used to find which need to be calculated first
bool operator >=(const Operator& LHS, const Operator& RHS)
{
    if (LHS._precedence >= RHS._precedence)
    {
        return true;
    }
    else {
        return false;
    }
}

bool operator <=(const Operator& LHS, const Operator& RHS)
{
    if (LHS._precedence <= RHS._precedence)
    {
        return true;
    }
    else {
        return false;
    }
}

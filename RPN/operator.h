#ifndef OPERATOR_H
#define OPERATOR_H
#include "token.h"

class Operator: public Token
{
public:
    Operator();
    Operator(string op);
    int Prec() const;
    string OP() const;
    void print() const;
    friend bool operator >=(const Operator& LHS, const Operator& RHS);
    friend bool operator <=(const Operator& LHS, const Operator& RHS);
private:
    int _precedence;
    string _op;
};

#endif // OPERATOR_H

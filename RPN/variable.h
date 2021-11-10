#ifndef VARIABLE_H
#define VARIABLE_H
#include "token.h"


class Variable : public Token
{
public:
    Variable();
    Variable(string s);
    void print() const;
    string VAR() const;
private:
    string _var;
};

#endif // VARIABLE_H

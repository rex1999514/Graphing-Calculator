#ifndef NUMBER_H
#define NUMBER_H
#include "token.h"

class Number : public Token
{
public:
    Number();
    Number(string s);
    Number(double num);
    void print() const;
    double NUM() const;
private:
    double _num;
    string var;
};

#endif // NUMBER_H

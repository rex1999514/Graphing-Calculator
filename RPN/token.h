#ifndef TOKEN_H
#define TOKEN_H
#include "constants.h"
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

class Token
{
public:
    Token();
    Token(TOKEN type);
    virtual ~Token();
    virtual void print() const;
    TOKEN type() const;
    friend ostream& operator <<(ostream& outs, const Token& t);
    friend ostream& operator <<(ostream& outs, const Token*& t);
private:
    TOKEN _type;
};

#endif // TOKEN_H

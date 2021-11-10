#ifndef TOKENIZE_H
#define TOKENIZE_H

#include "shunting_yard.h"
#include "rpn.h"

enum TOKEN_ERROR
{
    no_Para,
    OP_error
};


class Tokenize
{
public:
    Tokenize();
    void Tokenizing(string str, Queue<Token*>& result);
};

#endif // TOKENIZE_H

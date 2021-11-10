#ifndef EVALUATE_H
#define EVALUATE_H
#include "shunting_yard.h"
#include "rpn.h"
#include "tokenize.h"


class Evaluate
{
public:
    Evaluate();
    Evaluate(string str, double try_this = 0);
    bool isOperator(char now, char next);
    double eval();
private:
    double value;
};

#endif // EVALUATE_H

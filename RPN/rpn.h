#ifndef RPN_H
#define RPN_H
#include "operator.h"
#include "number.h"
#include "../CS8/!includes/StacknQueue/queue.h"
#include "../CS8/!includes/StacknQueue/stack.h"
#include "lparent.h"
#include "rparent.h"
#include "cmath"
enum EMPTY
{
    EMPTY_S,
    EMPTY_Q,
    UNRECOGNIZE_OP,
};


class RPN
{
public:
    RPN();
    RPN(Queue<Token*> input);
    RPN(string input_str);
    double rpn(double variable);
private:
    Queue<Token*> q;
};

#endif // RPN_H

#ifndef SHUNTING_YARD_H
#define SHUNTING_YARD_H

#include "../StackNQueue/queue.h"
#include "../StackNQueue/stack.h"
#include "number.h"
#include "operator.h"
#include "lparent.h"
#include "rparent.h"
#include "variable.h"

class Shunting_yard
{
public:
    Shunting_yard();
    Shunting_yard(Queue<Token*> infix);
    ~Shunting_yard();
    Queue<Token*> postfix();
private:
    Queue<Token*> _infix;
    Queue<Token*> _postfix;
};

#endif // SHUNTING_YARD_H

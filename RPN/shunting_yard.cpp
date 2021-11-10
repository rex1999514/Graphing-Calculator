#include "shunting_yard.h"

Shunting_yard::Shunting_yard()
{

}

Shunting_yard::~Shunting_yard()
{
    while(!_postfix.empty())
    {
        delete _postfix.pop();
    }
    while(!_infix.empty())
    {
        delete _infix.pop();
    }
}



Shunting_yard::Shunting_yard(Queue<Token*> infix)
{
    _infix = infix;
    _postfix = Queue<Token*>();
    Stack<Token*> s;
    Token* t;
    while(!infix.empty())
    {
        t = infix.pop();
        switch(t->type())
        {
        case NUMBER:
            //push to queue if it is number
            _postfix.push(t);
            break;
        case VARIABLE:
            _postfix.push(t);
            break;
        case OPERATOR:
            //if the stack is empty, push the operator to a stack
            if (static_cast<Operator*>(t)->OP() == "pi")
            {
                Token* pi = new Number(3.1415926);
                _postfix.push(pi);
                break;
            }
            if (s.empty())
            {
                s.push(t);
            }
            else
            {
                //if it is LPARENT just push the operator and the LPARENT back to the stack
                Token* t2 = s.pop();
                if (t2->type() == LPARENT)
                {
                    s.push(t2);
                    s.push(t);
                    break;
                }
                Operator* op = static_cast<Operator*>(t);
                Operator* op1 = static_cast<Operator*>(t2);
                //otherwise find which opeator need to be calculated first
                //push the operator that was in the stack to the queue if it should be calculated first
                if (*op1 >= *op)
                {
                    _postfix.push(t2);
                    s.push(t);
                }
                else {
                    s.push(t2);
                    s.push(t);
                }
            }
            break;
        case LPARENT:
            s.push(t);
            break;
        case RPARENT:
            //if see a RPARENT
            //push the operator to the queue until it see the LPARENT
            Token* t2 = s.pop();
            while(t2->type() != LPARENT)
            {
                _postfix.push(t2);
                t2 = s.pop();
            }
            break;
        }
    }
    //after everything, push the rest operator to the queue
    while(!s.empty())
    {
        Token* op = s.pop();
        _postfix.push(op);
    }
}

Queue<Token*> Shunting_yard::postfix()
{
    return _postfix;
}



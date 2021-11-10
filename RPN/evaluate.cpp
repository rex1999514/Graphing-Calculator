#include "evaluate.h"

Evaluate::Evaluate()
{

}

Evaluate::Evaluate(string str, double try_this)
{

//    Queue<Token*> t;
//    Tokenize Tokenize;

//    Tokenize.Tokenizing(str, t);
//            cout << "HIHI" << endl;
//    //turn infix to post fix
//    Shunting_yard Shunting(t);
//    Queue<Token*> postfix = Shunting.postfix();
    //find the result
    Queue<Token*> postfix;
    postfix.push(new Number(3));
    postfix.push(new Number(5));
    cout << postfix;
    RPN rpn(postfix);
    value = rpn.rpn(try_this);

}

double Evaluate::eval()
{
    return value;
}


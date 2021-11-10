#include "rpn.h"
#define PI 3.14159265

RPN::RPN()
{

}

RPN::RPN(Queue<Token*> input)
{
    q = input;
}

double RPN::rpn(double variable)
{
    Stack<Token*> s;
    Token* t;
    Token* vari;
    while(!q.Empty())
    {
        t = q.pop();
        double num1, num2;
        //after shunting yard, there should be no LPARENT and RPARENT in this case
        switch(t->type())
        {
        //push if number
        case NUMBER:
            s.push(t);
            break;
        case VARIABLE:
            vari = new Number(variable);
            s.push(vari);
            break;
        case OPERATOR:
            //pop two if operator
            //and do the calculation
            string str = static_cast<Operator*>(t)->OP();
            if (s.Empty())
            {
                throw EMPTY_S;
            }
            vari = s.pop();
            num1 = static_cast<Number*>(vari)->NUM();
            delete vari;
            if (!s.Empty())
            {
                vari = s.pop();
                num2 = static_cast<Number*>(vari)->NUM();
                delete vari;
            }
            if (str == "+")
            {
                Token* t = new Number(num1+num2);
                s.push(t);
            }
            else if (str == "-")
            {
                Token* t =new Number(num2 - num1);
                s.push(t);
            }
            else if (str == "*")
            {
                Token* t = new Number(num1 * num2);
                s.push(t);
            }
            else if (str == "/")
            {
                Token* t = new Number(num2 / num1);
                s.push(t);
            }
            else if (str == "^")
            {
                Token* t = new Number(pow(num2, num1));
                s.push(t);
            }
            else if (str == "Max")
            {
                Token* t = new Number(max(num1, num2));
                s.push(t);
            }
            else if (str == "Min")
            {
                Token* t = new Number(min(num1, num2));
                s.push(t);
            }
            else {
                if (str == "sin")
                {
                    t = new Number(sin(num1));
                }
                else if (str == "cos")
                {
                    t = new Number(cos(num1));
                }
                else if (str == "tan")
                {
                    t = new Number(tan(num1));
                }
                else if (str == "ln")
                {
                    t = new Number(log(num1));
                }
                else if (str == "pi")
                {
                    t = new Number(3.1415926);
                }
                else if (str == "csc")
                {
                    t = new Number(1/(sin(num1)));
                }
                else if (str == "cot")
                {
                    t = new Number(1/(tan(num1)));
                }
                else if (str == "sec")
                {
                    t = new Number(1/(cos(num1)));
                }
                else {
                    throw UNRECOGNIZE_OP;
                }
                Token* t2 = new Number(num2);
                s.push(t2);
                s.push(t);
            }
            break;
        }
    }
    //what left in the stack should be the result
    t = s.pop();
    double num = static_cast<Number*>(t)->NUM();
    delete t;
    cout << "num is " << num << endl;
    return num;
}

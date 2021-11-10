#include "tokenize.h"

Tokenize::Tokenize()
{

}

void Tokenize::Tokenizing(string str, Queue<Token*>& result)
{
    int LP_count = 0;
    int RP_count = 0;
    unsigned int pos = 0;
    while(pos < str.length())
    {
        if (isdigit(str[pos]))
        {
            string temp;
            while(isdigit(str[pos]) || str[pos] == '.')
            {
                temp += str[pos];
                pos++;
            }
            result.push(new Number(temp));
        }
        else if (isalpha(str[pos]))
        {
            string temp;
            if (pos == str.length() - 1)
            {
                temp += str[pos];
                result.push(new Variable(temp));
                pos++;
            }
            else if (isalpha(str[pos + 1]))
            {
                while(isalpha(str[pos]))
                {
                    temp += str[pos];
                    pos++;
                }
                result.push((new Operator(temp)));
            }
            else
            {
                temp += str[pos];
                result.push(new Variable(temp));
                pos++;
            }

        }
        else if (ispunct(str[pos]))
        {
            string temp;
            switch (str[pos])
            {
            case '(':
                LP_count++;
                temp += str[pos];
                result.push(new LParent);
                break;
            case ')':
                RP_count++;
                result.push(new RParent);
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                if (pos == str.length() - 1)
                {
                    throw OP_error;
                }
                temp += str[pos];
                result.push(new Operator(temp));
                break;
            default:
                break;
            }
            pos++;
        }
    }
    if (LP_count != RP_count)
    {
        throw no_Para;
    }
}

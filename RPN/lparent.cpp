#include "lparent.h"

//only hold a type of token
LParent::LParent():Token(LPARENT)
{
    s = "(";
}

LParent::LParent(string _s):Token(LPARENT)
{
    s = _s;
}

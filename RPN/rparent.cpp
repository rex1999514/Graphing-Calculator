#include "rparent.h"

//hole only the type RPARENT in a token
RParent::RParent():Token(RPARENT)
{
    s = ")";
}

RParent::RParent(string _s):Token(RPARENT)
{
    s = _s;
}

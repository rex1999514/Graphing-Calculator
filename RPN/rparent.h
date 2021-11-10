#ifndef RPARENT_H
#define RPARENT_H

#include "token.h"

class RParent : public Token
{
public:
    RParent();
    RParent(string _s);
private:
    string s;
};

#endif // RPARENT_H

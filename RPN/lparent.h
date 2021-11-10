#ifndef LPARENT_H
#define LPARENT_H

#include "token.h"


class LParent : public Token
{
public:
    LParent();
    LParent(string _s);
private:
    string s;
};

#endif // LPARENT_H

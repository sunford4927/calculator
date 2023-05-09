//Token.h

#pragma once

#include <iostream>

using namespace std;

#include <string.h>



class Token

{

    int priority;

public:

    virtual void View()const = 0;

    bool MoreThanPriority(Token* token);

protected:

    void SetPriority(int priority);

};



#include <vector>

using namespace std;

typedef vector<Token*> Tokens;

typedef Tokens::iterator TIter;

typedef Tokens::const_iterator CTIter;


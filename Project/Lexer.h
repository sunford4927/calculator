//Lexer.h

#pragma once

#include "Operand.h"

#include "Operator.h"

 

class Lexer

{

    Tokens tokens;

public:

    bool MakeToken(const char *expr);

    Tokens GetTokens()const;   

    ~Lexer();

};


#pragma once

#include "token.h"



class Operator :

    public Token

{

    char ch;

public:

    Operator(char ch);

    void View()const;

    int Calculate(int lvalue, int rvalue)const;



    static bool IsOperator(char ch);

    static bool IsOperator(const Token* token);

};


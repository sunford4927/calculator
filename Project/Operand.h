#pragma once
#include "Token.h"



class Operand :

    public Token

{

    int value;

public:

    Operand(int value);

    void View()const;

    int GetValue()const;

    static bool IsDigit(char ch);

    static int ConvertStrToInt(const char* str, int& index);

    static bool IsOperand(const Token* token);

};
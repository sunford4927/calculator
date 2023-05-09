#pragma once

#include "Lexer.h"

#include "SynAnalyzer.h"

#include "Parser.h"


// 수식 계산기를 표현할 Calculator
class Calculator

{

    char* expr;

    Tokens tokens;

public:

    Calculator(const char* expr);

    ~Calculator(void);

    void Run();

};
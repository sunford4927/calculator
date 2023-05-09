#pragma once

#include "Lexer.h"

#include "SynAnalyzer.h"

#include "Parser.h"


// ���� ���⸦ ǥ���� Calculator
class Calculator

{

    char* expr;

    Tokens tokens;

public:

    Calculator(const char* expr);

    ~Calculator(void);

    void Run();

};
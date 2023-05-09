#include "Lexer.h"



bool Lexer::MakeToken(const char* expr)

{

    tokens.clear();

    int i = 0;



    while (expr[i])

    {

        if (Operator::IsOperator(expr[i]))

        {

            tokens.push_back(new Operator(expr[i]));

            i++;

        }

        else

        {

            if (Operand::IsDigit(expr[i]))

            {

                int value = Operand::ConvertStrToInt(expr, i);

                tokens.push_back(new Operand(value));

            }

            else

            {

                return false;

            }

        }

    }

    return true;

}



Tokens Lexer::GetTokens()const

{

    return tokens;

}



Lexer::~Lexer()

{

    TIter seek = tokens.begin();

    TIter last = tokens.end();



    for (; seek != last; ++seek)

    {

        delete (*seek);

    }

}







//SynAnalyzer.h

#pragma once

#include "Operator.h"

#include "Operand.h"



class SynAnalyzer

{

public:

    static bool Analyze(Tokens tokens);

};
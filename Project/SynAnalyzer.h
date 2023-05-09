//SynAnalyzer.h

#pragma once

#include "Operator.h"

#include "Operand.h"



class SynAnalyzer

{

public:

    static bool Analyze(Tokens tokens);

};

bool SynAnalyzer::Analyze(Tokens tokens)
{
    int tcnt = tokens.size();
    if (tcnt % 2 == 0)
    {

        return false;

    }

    if (Operand::IsOperand(tokens[0]) == false)

    {

        return false;

    }



    for (int i = 1; i < tcnt; i += 2)

    {



        if (Operator::IsOperator(tokens[i]) == false)

        {

            return false;

        }

        if (Operand::IsOperand(tokens[i + 1]) == false)

        {

            return false;

        }

    }
        return true;
}

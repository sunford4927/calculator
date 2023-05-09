//Operand.cpp

#include "Operand.h"



Operand::Operand(int value)

{

    this->value = value;

    SetPriority(3);

}



void Operand::View()const

{

    cout << value << " ";

}



int Operand::GetValue()const

{

    return value;

}



bool Operand::IsDigit(char ch)

{

    return (ch >= '0') && (ch <= '9');

}

int Operand::ConvertStrToInt(const char* str, int& index)

{

    int value = 0;



    while (IsDigit(str[index]))

    {

        value = value * 10 + str[index] - '0';

        index++;

    }

    return value;

}



bool Operand::IsOperand(const Token* token)

{

    return dynamic_cast<const Operand*>(token) != 0;

}
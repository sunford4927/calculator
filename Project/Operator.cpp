#include "Operator.h"



Operator::Operator(char ch)

{

    this->ch = ch;

    if ((ch == '+') || (ch == '-'))

    {

        SetPriority(1);

    }

    else

    {

        SetPriority(2);

    }

}



void Operator::View()const

{

    cout << ch << " ";

}

int Operator::Calculate(int lvalue, int rvalue)const

{

    switch (ch)

    {

    case '+': return lvalue + rvalue;

    case '-': return lvalue - rvalue;

    case '*': return lvalue * rvalue;

    case '/':

        if (rvalue)

        {

            return lvalue / rvalue;

        }

        cout << "divide zero error" << endl;

        return 0;

    }

    throw "연산자 기호에 문제가 있습니다.";

}



bool Operator::IsOperator(char ch)

{

    return (ch == '+') || (ch == '-') || (ch == '*') || (ch == '/');

}



bool Operator::IsOperator(const Token* token)

{

    return dynamic_cast<const Operator*>(token) != 0;

}


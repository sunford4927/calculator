//Calculator.cpp

#include "Calculator.h"

Calculator::Calculator(const char* expr)

{

    int len_p1 = strlen(expr) + 1;

    this->expr = new char[len_p1];

    strcpy_s(this->expr, len_p1, expr);

}

Calculator::~Calculator(void)

{

    delete[] expr;

}

void Calculator::Run()

{

    cout << expr << "을 계산합니다. ..." << endl;

    Lexer lexer;

    if (lexer.MakeToken(expr))

    {

        tokens = lexer.GetTokens();

        if (SynAnalyzer::Analyze(tokens))

        {

            Parser parser(tokens);

            parser.Parsing();

            parser.PostOrderView();

            cout << expr << "=" << parser.Calculate() << endl;

        }

        else

        {

            cout << "수식에 사용한 표현이 문법에 맞지 않습니다." << endl;

        }

    }

    else

    {

        cout << "사용할 수 없는 기호가 있습니다." << endl;

    }

    cout << endl;

}
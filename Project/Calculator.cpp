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

    cout << expr << "�� ����մϴ�. ..." << endl;

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

            cout << "���Ŀ� ����� ǥ���� ������ ���� �ʽ��ϴ�." << endl;

        }

    }

    else

    {

        cout << "����� �� ���� ��ȣ�� �ֽ��ϴ�." << endl;

    }

    cout << endl;

}
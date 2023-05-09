//Parser.cpp

#include "Parser.h"



Parser::Parser(Tokens tokens)

{

    this->tokens = tokens;

}



Parser::~Parser(void)

{

    Clear(root);

}



void Parser::Clear(Node* sr)

{

    if (sr)

    {

        Clear(sr->lc);

        Clear(sr->rc);

        delete sr;

    }

}



void Parser::Parsing()

{

    int tcnt = tokens.size();

    root = new Node(tokens[0]);

    for (int i = 1; i < tcnt; i++)

    {

        Add(tokens[i]);

    }

}



void Parser::Add(Token* token)

{

    Node* now = new Node(token);



    Token* st = root->token;

    if (st->MoreThanPriority(token))

    {

        now->lc = root;

        root = now;

    }

    else

    {



        if (Operand::IsOperand(token) == false)

        {

            now->lc = root->rc;

            root->rc = now;

        }

        else

        {

            Node* pa = root;

            while (pa->rc)

            {

                pa = pa->rc;

            }

            pa->rc = now;

        }

    }

}



void Parser::PostOrderView()const

{

    PostOrder(root);

    cout << endl;

}



void Parser::PostOrder(Node* sr)const

{

    if (sr)

    {

        PostOrder(sr->lc);

        PostOrder(sr->rc);

        sr->token->View();

    }

}



int Parser::Calculate()

{

    return PostOrderCalculate(root);

}







int Parser::PostOrderCalculate(Node* sr)

{

    if (sr->lc)

    {

        int lvalue = PostOrderCalculate(sr->lc);

        int rvalue = PostOrderCalculate(sr->rc);

        Operator* op = dynamic_cast<Operator*>(sr->token);

        return op->Calculate(lvalue, rvalue);

    }

    else

    {

        Operand* op = dynamic_cast<Operand*>(sr->token);

        return op->GetValue();

    }

}
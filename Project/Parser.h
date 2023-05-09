#pragma once

#include "Operator.h"

#include "Operand.h"

class Parser

{

    Tokens tokens;

    struct Node

    {

        Token* token;

        Node* lc;

        Node* rc;

        Node(Token* token)

        {

            this->token = token;

            lc = rc = 0;

        }

    };

    Node* root;

public:

    Parser(Tokens tokens);

    ~Parser(void);

    void Parsing();

    void PostOrderView()const;

    int Calculate();

private:

    void Add(Token* token);

    void PostOrder(Node* sr)const;

    int PostOrderCalculate(Node* sr);

    void Clear(Node* sr);

};


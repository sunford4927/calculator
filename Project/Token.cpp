#include "Token.h"



bool Token::MoreThanPriority(Token* token)

{

    return priority >= token->priority;

}



void Token::SetPriority(int priority)

{

    this->priority = priority;

}


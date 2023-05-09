#include "Calculator.h"
#include <iostream>


int main()

{

    char * tc_exprs[6] =

    {
        
        "2+3-5*5+6/2", "23*5/2+4*6", "2+4*5#6",

        "2+3*5+", "3+36+-7", "45+3*5-2+5/2*7"

    };

    for (int i = 0; i < 6; i++)

    {

        Calculator* cal = new Calculator(tc_exprs[i]);

        cal->Run();

        delete cal;

    }

    return 0;

}
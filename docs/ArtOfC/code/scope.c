#include <stdio.h>
#include "static_scope.h"




double blocky(double apple)
{
    double quantity = 0.0;
    int i;

    for (i=0; i<10; i++)
    {
        double q = apple * i;       // start of scope for q

        quantity *= q;              // end of scope of q
    }
    return quantity;
}



int function_goto_scope() 
{
    int a = 1;
    int b = 2;

    if (a == 1) {
        goto a_state;
    } else {
        goto b_state;
    }
    

    a_state: {
        printf("This is a state.\n");
        int a = 11;
        return a;
    }

    b_state: {
        printf("This is b state.\n");
        return b;
    }
}


int main() {
    printf("%d\n", MAX_SCOPE_VALUE);
    // printf("Values: %d\n", function_goto_scope());
    return 0;
}
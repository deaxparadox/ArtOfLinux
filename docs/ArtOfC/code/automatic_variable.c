#include<stdio.h>
#include<stdlib.h>

int loop(int n)
{
    int m;                      // m in scope
    scanf("%d", &m);
    {
        int i;                  // both m and i in scope
        for (i=m; i<n; i++) 
            puts("i is local to sub-block\n");
    }
    return m;                   // m in scope, i gone
}


int outer_hide_impl()
{
    int x = 30;                 // Original x

    printf("x in outer block: %d at %p\n", x, &x);
    
    {
        int x = 7;              // new x, hides first x
        printf("x in inner block: %d at %p\n", x, &x);
    }
    
    printf("x in outer block: %d at %p\n", x, &x);

    while (x++ < 33)            // Original x
    {       
        int x = 100;            // new x, hides first x
        x++;
        printf("x in while loop: %d at %p\n", x, &x);
    }

    printf("x in outer block: %d at %p\n", x, &x);

}


int main()
{
    outer_hide_impl();
    exit(0);
}
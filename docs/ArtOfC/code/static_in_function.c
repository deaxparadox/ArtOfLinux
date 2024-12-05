#include <stdio.h>

void with_static(int number)
{
    static int total = 0;
    total+=number;
    printf("number: %d, total: %d\n", number, total);
}

int no_static()
{
    printf("total: ", tota)

}

int main()
{
    with_static(1);
    with_static(2);
    with_static(3);
    with_static(4);
    with_static(5);
    return 0;
}

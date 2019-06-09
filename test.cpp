#include <iostream>

int main()
{
    int num = 20;
    int *p = &num;
    printf("*p = %d\n", *p);
    printf(" &num = %d\n", &num);
    printf("p = %d\n", p);
    printf(" &p=%d\n", &p);
    return 0;
}
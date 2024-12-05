#include <stdio.h>
int main()
{
    int a, b, smaller;
    scanf("%d %d", &a, &b);
    int n = 1;
    smaller = a < b ? a : b;
    for (int i = 2; i <= smaller; i++)
    {

        if (a % i == 0 && b % i == 0)
        {
            n = 0;
            break;
        }
    }
    if (n == 1)
    {
        printf("Coprime\n");
    }
    else
    {
        printf("Not coprime\n");
    }
    return 0;
}
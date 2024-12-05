#include <stdio.h>
int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    int n = 1;
    for (int i = 2; i < a && i < b; i++)
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
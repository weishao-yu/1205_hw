#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int sum = 0;
    for (int i = 2; i <= n; i = i + 2)
    {
        if (n % i == 0)
        {
            sum = sum + i;
        }
    }
    printf("%d", sum);
    return 0;
}
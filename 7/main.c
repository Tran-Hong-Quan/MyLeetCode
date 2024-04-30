#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

int reverse(int x)
{
    if (x == INT_MAX || x == INT_MIN)
        return 0;
    int s = x > 0 ? 1 : -1;
    x = abs(x);

    long int res = 0;
    while (x > 0)
    {
        res = res * 10 + x % 10;
        if (res != (int)res)
        {
            return 0;
        }
        x /= 10;
    }
    return res * s;
}

int main()
{
    int x = 1534236469;
    printf("%d", reverse(x));
}
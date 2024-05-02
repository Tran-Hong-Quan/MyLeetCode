#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>

bool isPalindrome(int x)
{
    if(x < 0)
    {
        return false;
    }
    char strX[10] = {0};
    int p = 0;
    while (x != 0)
    {
        strX[p++] = x % 10;
        x /= 10;
    }

    int i = 0,j = p - 1;
    while (i <= j)
    {
        if(strX[i]!=strX[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int main()
{
    printf("%d", isPalindrome(-12321));
}
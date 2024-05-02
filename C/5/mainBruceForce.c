#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

int isPalidrome(char *s, int i, int j)
{
    while (i <= j)
    {
        if (s[i++] != s[j--])
        {
            return 0;
        }
    }
    return 1;
}

char *longestPalindrome(char *s)
{
    int len = strlen(s);
    int start = 0, end = 0;
    for (int i = 0; i < len; i++)
    {
        for (int j = len - 1; j >= i; j--)
        {
            if (isPalidrome(s, i, j) && end - start < j - i)
            {
                start = i;
                end = j;
            }
        }
    }
    char *res = (char *)calloc(end - start + 2, 1);
    strncpy(res, s + start, end - start + 1);
    return res;
}

int main()
{
    char s[] = "cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccCCC";

    // printf("%s", getPalidromeFromLast(s, 0));
    printf("%s", longestPalindrome(s));
}
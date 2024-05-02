#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

int isPalidrome(char *s)
{
    // printf("is palin %s\n", s);
    int len = strlen(s);
    int i = 0, j = len - 1;
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
    char *res = NULL;
    for (int i = 0; i < len; i++)
    {
        for (int j = len - 1; j >= i; j--)
        {
            char *temp = (char *)malloc(j - i + 2);
            strncpy(temp, s + i, j - i + 1);
            temp[j - i + 1] = 0;
            if (isPalidrome(temp))
            {
                if (res == NULL)
                {
                    res = temp;
                }
                else if (strlen(res) < strlen(temp))
                {
                    free(res);
                    res = temp;
                }
            }
            else
            {
                free(temp);
            }
        }
    }
    return res;
}

int main()
{
    char s[] = "cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccCCC";

    // printf("%s", getPalidromeFromLast(s, 0));
    printf("%s", longestPalindrome(s));
}
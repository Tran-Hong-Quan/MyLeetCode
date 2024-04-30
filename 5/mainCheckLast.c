#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

int isPalidrome(char *s, int i, int j)
{
    // printf("is palin %s\n", s);
    int len = strlen(s);
    while (i <= j)
    {
        if (s[i++] != s[j--])
        {
            return 0;
        }
    }
    return 1;
}

char *getPalidromeFromLast(char *s, int lastIndex)
{
    int maxLength = 1;
    int startIndex = lastIndex;
    for (int i = lastIndex - 1; i >= 0; i--)
    {
        if (isPalidrome(s, i, lastIndex))
        {
            startIndex = i;
            break;
        }
    }
    char *res = (char *)calloc(lastIndex - startIndex + 2, 1);
    strncpy(res, s + startIndex, lastIndex - startIndex + 1);
    return res;
}

char *longestPalindrome(char *s)
{
    int len = strlen(s);
    if (len == 0)
    {
        return "";
    }
    if (len == 1)
    {
        char *res = (char *)malloc(2);
        res[0] = s[0];
        res[1] = 0;
        return res;
    }

    char *maxPali = NULL;

    for (int i = 1; i <= len; i++)
    {
        char *lastPali = getPalidromeFromLast(s, i - 1);
        if (maxPali == NULL)
        {
            maxPali = lastPali;
            // printf("len = %d,max = %s,last = %s\n", i, maxPali, lastPali);
        }
        else if (strlen(lastPali) > strlen(maxPali))
        {
            free(maxPali);
            maxPali = lastPali;
            // printf("len = %d,max = %s,last = %s\n", i, maxPali, lastPali);
        }
    }

    return maxPali;
}

int main()
{
    char s[] = "babad";

    // printf("%s", getPalidromeFromLast(s, 0));
    printf("%s", longestPalindrome(s));
}
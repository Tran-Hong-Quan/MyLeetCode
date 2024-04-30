#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

int containChar(char *s, int start, int end, char t)
{
    for (int i = start; i <= end; i++)
    {
        if (s[i] == t)
        {
            return 1;
        }
    }
    return 0;
}

int lengthOfLongestSubstring(char *s)
{
    int max = 0;
    int len = strlen(s);
    if (len == 0)
        return 0;
    if (len == 1)
        return 1;
    int sl = 1;
    for (int i = 0; i < len; i++)
    {
        sl = 1;
        for (int j = i + 1; j < len; j++)
        {
            if (!containChar(s, i, j - 1, s[j]))
            {
                sl++;
                //printf("sl = %d, i = %d\n", sl, i);
            }
            else
            {
                break;
            }
        }
        if (sl > max)
        {
            max = sl;
        }
    }
    return max;
}

int main()
{
    printf("Max = %d", lengthOfLongestSubstring("abcabcbb"));
}
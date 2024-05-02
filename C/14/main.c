#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>

char *longestCommonPrefix(char **strs, int strsSize)
{
    char *res = calloc(200, 1);

    int i = 0;
    while (i < strlen(strs[0]))
    {
        char cc = strs[0][i];

        for (int j = 1; j < strsSize; j++)
        {
            char *s = strs[j];
            if (i >= strlen(s))
                return res;
            if (s[i] != cc)
                return res;
        }
        res[i++] = cc;
    }

    return res;
}

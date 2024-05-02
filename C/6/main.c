#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

char *convert(char *s, int numRows)
{
    int len = strlen(s);
    int div = 2 * numRows - 2;
    if (len == 1 || div == 0)
    {
        return s;
    }

    int p = 0;
    char *res = (char *)calloc(len + 1, 1);

    for (int i = 0; i < len; i += div)
    {
        res[p++] = s[i];
    }

    int offset = 1;
    while (offset < div - offset)
    {
        for (int i = offset; i < len; i += div)
        {
            res[p++] = s[i];
            if (i + div - 2 * offset < len)
                res[p++] = s[i + div - 2 * offset];
        }
        offset++;
    }

    for (int i = numRows - 1; i < len; i += div)
    {
        res[p++] = s[i];
    }

    return res;
}

int main()
{
    char s[] = "PAYPALISHIRING";
    int numRows = 4;
    printf("Ret = %s", convert(s, numRows));
}

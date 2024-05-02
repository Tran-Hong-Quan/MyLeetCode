#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char *mergeAlternately(char *word1, char *word2);

int main()
{
    FILE *file;
    char str1[100], str2[100];

    file = fopen("input.txt", "r");

    fscanf(file, "%s", str1);
    fscanf(file, "%s", str2);
    char *res = mergeAlternately(str1, str2);

    printf("Chuoi thu nhat: %s\n", str1);
    printf("Chuoi thu hai: %s\n", str2);
    printf("Chuoi thu ba: %s\n", res);
    fclose(file);

    return 0;
}

char *mergeAlternately(char *word1, char *word2)
{
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    int lenRes = len1 + len2;
    char *res = (char *)calloc(lenRes + 1,0);

    for (int i = 0, i1 = 0, i2 = 0; i < lenRes; i++)
    {
        if (i % 2 == 0)
        {
            if (i1 < len1)
            {
                res[i] = word1[i1];
                i1++;
            }
            else if (i2 < len2)
            {
                res[i] = word2[i2];
                i2++;
            }
        }
        else
        {
            if (i2 < len2)
            {
                res[i] = word2[i2];
                i2++;
            }
            else if (i1 < len1)
            {
                res[i] = word1[i1];
                i1++;
            }
        }
    }

    return res;
}
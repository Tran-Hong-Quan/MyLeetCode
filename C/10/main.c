#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>

void **create2DArray(int rows, int cols, unsigned long long segmentSize)
{
    void **array = (void **)calloc(rows, segmentSize);
    if (array == NULL)
    {
        printf("Không đủ bộ nhớ!\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < rows; i++)
    {
        array[i] = (int *)calloc(cols, segmentSize);
        if (array[i] == NULL)
        {
            printf("Không đủ bộ nhớ!\n");
            exit(EXIT_FAILURE);
        }
    }

    return array;
}

void free2DArray(void **array, int rows)
{
    // Giải phóng từng hàng của mảng
    for (int i = 0; i < rows; i++)
    {
        free(array[i]);
    }

    // Giải phóng mảng con trỏ chứa các con trỏ hàng
    free(array);
}

bool isMatch(char *s, char *p)
{
    int pLen = strlen(p);
    int sLen = strlen(s);

    int **dp = (int **)create2DArray(pLen + 1, sLen + 1, sizeof(int));
    dp[0][0] = 1;

    for (int i = 0; i < sLen + 1; i++)
    {
        for (int j = 0; j < pLen + 1; j++)
        {
            if (p[j] == '*')
            {
            }
        }
    }

    free2DArray(dp, pLen + 1);
}

int main()
{
    char s[] = "aa";
    char p[] = "a*";

    int **arr = (int **)create2DArray(2, 2, 8);
    arr[0][0] = 1;
    arr[1][1] = 2;
    printf("%d,", arr[1][0]);
    // printf("Is Match = %d", isMatch(s, p));
}
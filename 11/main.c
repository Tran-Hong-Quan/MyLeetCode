#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>

int minInt(int a, int b)
{
    if (a < b)
        return a;
    return b;
}

int maxArea(int *height, int heightSize)
{
    int res = 0;
    int l = 0, r = heightSize - 1;
    while (l < r)
    {
        int v = minInt(height[l], height[r]) * (r - l);
        if (v > res)
        {
            res = v;
        }
        if (height[l] > height[r])
        {
            r--;
        }
        else
        {
            l++;
        }
    }

    return res;
}

int main()
{
    int s[] = {1, 2, 4, 3};
    printf("%d", maxArea(s, sizeof(s) / sizeof(int)));
}
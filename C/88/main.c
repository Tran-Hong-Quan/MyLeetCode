#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

void printArr(int *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void merge(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n)
{
    if (m == 0)
    {
        for (int i = 0; i < n; i++)
        {
            nums1[i] = nums2[i];
        }
        return;
    }
    if (n == 0)
    {
        return;
    }

    int *nums = (int *)malloc(sizeof(int) * m);
    memcpy(nums, nums1, m * sizeof(int));

    int i = 0, j = 0;
    nums1Size = n + m;
    int p = 0;
    while (p < nums1Size)
    {
        if (i < m && j < n)
        {
            if (nums[i] < nums2[j])
            {
                nums1[p] = nums[i];
                i++;
            }
            else
            {
                nums1[p] = nums2[j];
                j++;
            }
        }
        else
        {
            if (i < m)
            {
                nums1[p] = nums[i];
                i++;
            }
            if (j < n)
            {
                nums1[p] = nums2[j];
                j++;
            }
        }

        p++;
    }

    free(nums);
}

int main()
{
    int nums1[] = {4,0,0,0,0,0};
    int nums2[] = {1,2,3,5,6};

    merge(nums1, -1, 1, nums2, -1, 5);

    printArr(nums1, 6);
    return 0;
}
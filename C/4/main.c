#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size);

int main()
{
    int nums1[] = {1, 2};
    int nums2[] = {3, 4};

    printf("Median = %f", findMedianSortedArrays(nums1, 2, nums2, 2));
}

void printArr(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
    int i = 0, j = 0, p = 0, len = nums1Size + nums2Size;
    int *arr = (int *)malloc(4 * len);

    while (p <= len / 2)
    {
        if (i < nums1Size && j < nums2Size)
        {
            if (nums1[i] < nums2[j])
            {
                arr[p++] = nums1[i++];
            }
            else
            {
                arr[p++] = nums2[j++];
            }
        }
        else
        {
            if (i < nums1Size)
            {
                arr[p++] = nums1[i++];
            }
            if (j < nums2Size)
            {
                arr[p++] = nums2[j++];
            }
        }
    }

    double res;

    if (len % 2)
    {
        res = arr[len / 2];
    }
    else
    {
        res = ((double)(arr[len / 2] + arr[len / 2 - 1])) / 2;
    }

    free(arr);

    return res;
}
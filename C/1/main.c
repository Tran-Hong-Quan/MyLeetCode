#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    int *res = (int *)malloc(sizeof(int) * 2);
    *returnSize = 2;

    for (int i = 0; i < numsSize; i++)
    {
        for (int j = i + 1; j < numsSize; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                res[0] = i;
                res[1] = j;
                break;
            }
        }
    }
    return res;
}

int main()
{
    FILE *file;
    int target, n;

    file = fopen("input.txt", "r");

    if (file == NULL)
    {
        printf("Khong the mo file!\n");
        return 1;
    }

    fscanf(file, "%d", &target);
    fscanf(file, "%d", &n);

    if (n < 0)
    {
        printf("So luong phan tu khong hop le!\n");
        fclose(file);
        return 1;
    }

    int *numbers = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        fscanf(file, "%d", &numbers[i]);
    }

    printf("Target: %d\n", target);
    printf("So phan tu: %d\n", n);
    printf("Cac so: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    int rSize;
    int *r = twoSum(numbers, n, target, &rSize);
    printf("Ket qua: %d %d\n", r[0], r[1]);

    free(numbers);
    free(r);
    fclose(file);

    return 0;
}
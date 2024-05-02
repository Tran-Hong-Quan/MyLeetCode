#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int minFallingPathSum(int **grid, int gridSize, int *gridColSize);
void printMatrix(int **arr, int rol,int col);
int **createMatrix(int col, int rol);
void freeMatrix(int **matrix, int rol);

int main()
{
    FILE *file;
    int n, i, j;

    // Mở file
    file = fopen("input.txt", "r");

    // Đọc kích thước của ma trận
    fscanf(file, "%d", &n);

    // Cấp phát bộ nhớ cho ma trận
    int **matrix = createMatrix(n, n);

    // Đọc các phần tử của ma trận từ file
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            fscanf(file, "%d", &matrix[i][j]);
        }
    }

    // Đóng file
    fclose(file);

    // In ra ma trận đã đọc
    printf("Ma tran da doc:\n");
    printMatrix(matrix, n,n);

    int minF = minFallingPathSum(matrix, n, &n);
    printf("Min f = %d", minF);

    // Giải phóng bộ nhớ
    freeMatrix(matrix, n);

    return 0;
}

int **createMatrix(int rol, int col)
{
    int **matrix = (int **)malloc(rol * sizeof(int *));
    for (int i = 0; i < rol; i++)
    {
        matrix[i] = (int *)malloc(col * sizeof(int));
    }
    return matrix;
}

void freeMatrix(int **matrix, int rol)
{
    for (int i = 0; i < rol; i++)
    {
        free(matrix[i]);
    }

    free(matrix);
}

void printMatrix(int **arr, int rol,int col)
{
    for (int i = 0; i < rol; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int minFall(int *arr, int size, int col)
{
    int min = 2147483647;
    for (int i = 0; i < size; i++)
    {
        if (col != i)
        {
            if (min > arr[i])
            {
                min = arr[i];
            }
        }
    }
    return min;
}

int printDP(int *arr, int size)
{
    printf("DP: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int minFallingPathSum(int **grid, int gridSize, int *gridColSize)
{
    int **dp = createMatrix(gridSize+1, gridSize);

    for (int i = 0; i < gridSize; i++)
    {
        dp[0][i] = 0;
    }

    for (int i = 0; i < gridSize; i++)
    {
        for (int j = 0; j < gridSize; j++)
        {
            dp[i+1][j] = minFall(dp[i], gridSize, j) + grid[i][j];
        }
        //printDP(dp[i], gridSize);
        //printf("Matrix: \n");
        //printMatrix(dp,gridSize+1,gridSize);
    }

    int res = minFall(dp[gridSize], gridSize, -1);

    freeMatrix(dp, gridSize+1);

    return res;
}

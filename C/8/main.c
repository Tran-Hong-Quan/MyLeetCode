#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

int isDigit(char c)
{
    return c >= '0' && c <= '9';
}

int toDigit(char c)
{
    return c - '0';
}

int myAtoi(char *s)
{
    int len = strlen(s);
    int p = 0;
    long int res = 0;
    while (s[p] == ' ')
    {
        p++;
        if (p >= len - 1)
            return res;
    }
    int mul = 1;
    if (s[p] == '-')
    {
        mul = -1;
        p++;
    }
    else if (s[p] == '+')
    {
        p++;
    }

    int numLen = 0;
    while (isDigit(s[p]) && p < len)
    {
        res = res * 10 + toDigit(s[p++]);
        if (res >= INT_MAX && mul == 1)
        {
            return INT_MAX;
        }
        if (mul == -1 && res >= (long int)2147483648)
        {
            return INT_MIN;
        }
    }

    res *= mul;

    return res;
}

int main()
{
    char str[] = "-42"; // Chuỗi ký tự đại diện cho số nguyên 12345

    // Sử dụng hàm atoi để chuyển chuỗi str thành số nguyên và gán vào biến intValue
    // int intValue = atoi(str);
    int intValue = myAtoi(str);

    // In ra giá trị số nguyên đã chuyển
    printf("Giá trị số nguyên: %d\n", intValue);

    return 0;
}

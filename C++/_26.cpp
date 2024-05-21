#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int p = 0;
        int size = nums.size();
        for (int i = 1; i < size; i++)
        {
            if (nums[i] != nums[i - 1])
            {
                nums[p++] = nums[i - 1];
            }
        }
        if (nums[p] != nums[size - 1])
        {
            nums[p++] = nums[size - 1];
        }
        return p;
    }
};
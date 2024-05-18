#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int size = cost.size();
        if (size <= 1)
            return 0;
        int *dp = new int[size];
        dp[0] = 0;
        dp[1] = cost[1];
        for (int i = 2; i < size; i++)
        {
            dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
        }
        return min(dp[size - 1], dp[size - 2]);
    }
};

int main()
{
    Solution s;
    cout << s.minCostClimbingStairs({10, 15, 20});
}

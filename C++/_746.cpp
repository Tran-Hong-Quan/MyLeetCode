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
        int pre = cost[0];
        int cur = cost[1];
        for (int i = 2; i < size; i++)
        {
            int t = cur;
            cur = min(pre, cur) + cost[i];
            pre = t;
        }
        return min(pre,cur);
    }
};

int main()
{
    Solution s;
    cout << s.minCostClimbingStairs({10, 15, 20});
}

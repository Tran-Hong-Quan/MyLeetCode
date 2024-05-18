#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if(size == 0) return 0;
        if(size == 1) return nums[0];
        if(size == 2) return max(nums[1],nums[0]);

        int*dp = new int[size];
        dp[0] = nums[0];
        dp[1] = max(nums[1],nums[0]);;

        for (int i = 2; i < size; i++)
        {
            dp[i] = max(dp[i-2] + nums[i],dp[i-1]);
            cout<<i<<" "<<dp[i]<<endl;
        }
        return max(dp[size-1],dp[size-2]);
    }
};

int main()
{
    Solution s;
    cout << s.rob({2,1,1,2});
}

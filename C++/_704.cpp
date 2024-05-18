#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <climits>

using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int l = 0;
        int r = nums.size() - 1;
        int mid;

        while (l <= r)
        {
            mid = (l + r) / 2;
            int n = nums[mid];
            cout<<n<<endl;

            if (n == target)
            {
                return mid;
            }
            if (n < target)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }

        return -1;
    }
};


int main()
{
    Solution s;
    vector<int> nums = {-1,0,3,5,9,12};
    auto r = s.search(nums,9);
    cout<<r;
}
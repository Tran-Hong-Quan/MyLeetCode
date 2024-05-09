#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    long long maximumHappinessSum(vector<int> &happiness, int k)
    {
        long long res = 0;
        sort(happiness.begin(), happiness.end(), [](int a, int b) -> bool
             { return a > b; });

        for (int i = 0; i < k; i++)
        {
            if (happiness[i] - i <= 0)
                break;
            res += happiness[i] - i;
        }

        return res;
    }
};

int main()
{
    Solution s;
    vector<int> h = {1, 2, 3};
    cout << s.maximumHappinessSum(h, 2);
}
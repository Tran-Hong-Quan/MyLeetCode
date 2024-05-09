
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int buyPrice = prices[0];
        int maxProfit = 0;

        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] < buyPrice)
            {
                buyPrice = prices[i];
            }
            int profit = prices[i] - buyPrice;
            if (maxProfit < profit)
            {
                maxProfit = profit;
            }
        }

        return maxProfit;
    }
};

int main()
{
    Solution s;
    vector<int> h = {7, 1, 5, 3, 6, 4};
    cout << s.maxProfit(h);
}
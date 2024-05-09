#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<vector<string>> dp;
        dp.push_back({"()"});

        for (int i = 1; i < n; i++)
        {
            vector<string> gp;
            for (auto d : dp[i - 1])
            {
                string s1 = d + "()";
                string s2 = "()" + d ;
                string s3 = "(" + d + ")";
                gp.push_back(s1);
                if(s1 != s2) gp.push_back(s2);
                gp.push_back(s3);
            }
            dp.push_back(gp);
        }

        sort(dp[n-1].begin(),dp[n-1].end());

        return dp[n - 1];
    }
};

int main()
{
    Solution s;
    auto r = s.generateParenthesis(3);
    for (auto i : r)
    {
        cout << i << endl;
    }
}
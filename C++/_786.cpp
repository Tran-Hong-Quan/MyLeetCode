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
    vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k)
    {
        unordered_map<int, stack<int>> stacks;
        for (int i = 0; i < arr.size(); i++)
        {
            stack<int> s;
            for (int j = i+1; j < arr.size(); j++)
            {
                s.push(arr[j]); 
                //cout << arr[i] << " " << arr[j]<<endl;
            }
            stacks[arr[i]] = s;
        }
        vector<vector<int>> nums;

        while (stacks.size() != 0)
        {
            int minStack;
            double minValue = INT_MAX;
            for (auto i = stacks.begin(); i != stacks.end(); i++)
            {
                if (i->second.empty())
                {
                    if (minValue < i->first)
                    {
                        minValue = i->first;
                        minStack = i->first;
                    }
                    stacks.erase(i);
                }
                else
                {
                    double v = INT_MAX;
                    v = (double)i->second.top() / i->first;
                    if (v < minValue)
                    {
                        minValue = v;
                        minStack = i->first;
                    }
                }
            }
            if(stacks.count(minStack)==0) break;
            cout << "HEHE: "<<minStack << " " << stacks[minStack].top()<<endl;
            nums.push_back({minStack,stacks[minStack].top()});
            stacks[minStack].pop();
        }

        return nums[k];
    }
};

int main()
{
    Solution s;
    vector<int> arr = {1, 2, 3, 5};
    int k = 3;
    auto r = s.kthSmallestPrimeFraction(arr, k);
    for (auto i : r)
    {
        cout << i << endl;
    }
}

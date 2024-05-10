#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

class Solution
{
public:
    int checkChar(char l, char r)
    {
        if (r == '(' || r == '[' || r == '{')
        {
            return 1;
        }
        if (l == '(')
        {
            if (r == ')')
                return 0;
            else
                return -1;
        }
        if (l == '[')
        {
            if (r == ']')
                return 0;
            else
                return -1;
        }
        if (l == '{')
        {
            if (r == '}')
                return 0;
            else
                return -1;
        }
        return -1;
    }

    bool isValid(string s)
    {
        stack<char> stk;
        for (auto c : s)
        {
            if (stk.empty())
            {
                stk.push(c);
                continue;
            }
            int check = checkChar(stk.top(),c);
            if(check == 1)
                stk.push(c);
            else if(check == 0)
                stk.pop();
            else
                return false;
        }
        return stk.empty();
    }
};

int main()
{
    Solution s;
    auto r = s.isValid("()()()");
    cout<<r;
}
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        unordered_map<char, int> hash;

        if (s.length() != t.length())
            return false;

        for (auto c : s)
        {
            if (hash.count(c) == 0)
            {
                hash[c] = 1;
            }
            else
            {
                hash[c]++;
            }
        }

        for (auto c : t)
        {
            if (hash.count(c) == 0)
                return false;
            if (hash[c] != 0)
                hash[c]--;
            else
                return false;
        }

        return true;
    }
};

int main()
{
    Solution s;
    cout<<s.isAnagram("car","rat");
}

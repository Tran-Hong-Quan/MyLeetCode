#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map <string,vector<string>> map;

        for(auto s : strs){
            auto t = s;
            sort(t.begin(),t.end());
            map[t].push_back(s);
        }

        vector<vector<string>> res;
        for(auto m : map){
            res.push_back(m.second);
        }

        return res;
    }
};
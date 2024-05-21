#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    bool isMatch(string haystack, string needle,int index){
        int hLength = haystack.length(), nLength = needle.length();
        if(hLength < index + nLength) return false;
        
        for (int i = 0; i < nLength; i++)
        {
            if(needle[i]!=haystack[index++])
            {
                return false;
            }
        }
        return true;
    }
    int strStr(string haystack, string needle) {
        int hLen = haystack.length();
        if(hLen == 0 && needle.length() == 0) return 0;
        for (int i = 0; i < hLen; i++)
        {
            if(isMatch(haystack,needle,i))
            {
                return 0;
            }
        }
        return -1;
    }
};

int main(){
    Solution s;
    cout<<s.strStr("1","1");
}
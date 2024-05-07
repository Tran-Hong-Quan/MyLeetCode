#include "_217.h"

bool _217::containsDuplicate(std::vector<int>& nums)
{
    std::unordered_set<int> hash;

    for (auto n : nums)
    {
        if (hash.find(n) != hash.end())
        {
            return true;
        }
        hash.insert(n);
    }

    return false;
}

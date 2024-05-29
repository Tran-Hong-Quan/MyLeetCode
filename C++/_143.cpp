#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    void reorderList(ListNode *head)
    {
        vector<ListNode*> list;
        ListNode*p = head;
        while (p != nullptr)
        {
            list.push_back(p);
            p = p->next;
        }

        
    }
};
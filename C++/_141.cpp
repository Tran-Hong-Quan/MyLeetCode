#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode*slow = head;
        ListNode*fast = head->next;

        while (fast!=NULL)
        {
            if(fast == slow) return true;
            fast = fast->next;
            if(fast==NULL) return false;
            if(fast == slow) return true;
            fast = fast->next;
            slow = slow->next;
        }
        return false; 
    }
};
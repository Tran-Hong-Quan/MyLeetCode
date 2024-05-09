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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *head = NULL;
        ListNode *p = NULL;
        ListNode *p1 = list1;
        ListNode *p2 = list2;

        while (p1 != NULL || p2 != NULL)
        {
            ListNode *next;

            if (p1 == NULL)
            {
                next = p2;
                p2 = p2->next;
            }
            else if (p2 == NULL)
            {
                next = p1;
                p1 = p1->next;
            }
            else
            {
                if (p1->val < p2->val)
                {
                    next = p1;
                    p1 = p1->next;
                }
                else
                {
                    next = p2;
                    p2 = p2->next;
                }
            }

            if(p==NULL){
                head = next;
                p = head;
            }
            else{
                p->next = next;
                p = next;
            }
        }

        return head;
    }
};
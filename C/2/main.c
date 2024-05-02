#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *createNode()
{
    struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
    node->next = NULL;
    return node;
}

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *head = createNode();
    struct ListNode *p = head;
    int r = 0;
    int val = 0;

    while (l1 != NULL || l2 != NULL || r == 1)
    {
        val = r;
        if (l1 != NULL)
        {
            val += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL)
        {
            val += l2->val;
            l2 = l2->next;
        }
        if (val >= 10)
        {
            val %= 10;
            r = 1;
        }
        else
        {
            r = 0;
        }
        p->val = val;
        if (l1 != NULL || l2 != NULL || r == 1)
            p->next = createNode();
        p = p->next;
    }

    return head;
}

int main()
{
}
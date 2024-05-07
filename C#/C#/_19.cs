using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LeetCode
{
    public class _19
    {

        public class ListNode
        {
            public int val;
            public ListNode next;
            public ListNode(int val = 0, ListNode next = null)
            {
                this.val = val;
                this.next = next;
            }
        }

        public ListNode RemoveNthFromEnd(ListNode head, int n)
        {
            ListNode res = new ListNode(-1, head);
            ListNode d = res;

            for (int i = 0;i<n;i++)
            {
                head = head.next;
            }

            while(head != null)
            {
                head = head.next;
                d = d.next;
            }

            d.next = d.next.next;

            return res.next;
        }
    }
}

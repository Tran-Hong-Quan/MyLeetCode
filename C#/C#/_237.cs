using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LeetCode
{
    public class _237
    {
        public class ListNode
        {
            public int val;
            public ListNode next;
            public ListNode(int x) { val = x; }
        }

        public void DeleteNode(ListNode node)
        {
            node.val = node.next.val;   
            node.next = node.next.next;
        }
    }
}

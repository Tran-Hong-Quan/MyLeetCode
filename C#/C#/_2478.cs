using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LeetCode
{
    public class _2478
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



        public ListNode RemoveNodes(ListNode head)
        {
            ListNode p = head;
            Stack<ListNode> stack = new Stack<ListNode>();

            while (p != null)
            {
                if (stack.Count == 0)
                {
                    stack.Push(p);
                    head = p;
                    p = p.next;
                    continue;
                }

                while (p.val > stack.Peek().val)
                {
                    stack.Pop();
                    if (stack.Count > 0)
                    {
                        stack.Last().next = p;
                    }
                    else if (stack.Count == 0)
                    {
                        head = p;
                        break;
                    }
                }
                stack.Push(p);
                p = p.next;

            }
            return head;
        }

        private void AddNode(ListNode head,int val)
        {
            ListNode p = head;
            while (p.next != null)
            {
                p = p.next;
            }
            p.next = new ListNode(val);
        }

        public static void Test()
        {
            _2478 _2478 = new _2478();
            ListNode head = new ListNode();
            head.val = 5;
            _2478.AddNode(head, 2);
            _2478.AddNode(head, 13);
            _2478.AddNode(head, 3);
            _2478.AddNode(head, 8);

            head = _2478.RemoveNodes(head);

            Console.Write("[");
            while(head != null)
            {
                Console.Write(head.val + " ");
                head = head.next;
            }
            Console.Write("]");
        }

    }
}

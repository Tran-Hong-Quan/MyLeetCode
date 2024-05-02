using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LeetCode
{
    public class _2441_LPITEWIN
    {
        public int FindMaxK(int[] nums)
        {
            int res = -1;
            var numsSorted = (int[])nums.Clone();
            Array.Sort(numsSorted);
            Dictionary<int, int> dic = new Dictionary<int, int>();
            for (int i = 0; i < nums.Length; i++)
            {
                if (!dic.ContainsKey(nums[i]))
                {
                    dic.Add(nums[i], i);
                }
            }

            for (int i = numsSorted.Length - 1; i > -1; i--)
            {
                int num = numsSorted[i];
                if (num < 1)
                {
                    break;
                }

                if (dic.ContainsKey(-num))
                {
                    res = num;
                    break;
                }
            }

            return res;
        }

        public static void Test()
        {
            var sl = new _2441_LPITEWIN();
            int[] nums = { -1, 10, 6, 7, -7, 1 };
            Console.WriteLine(sl.FindMaxK(nums));
        }
    }
}

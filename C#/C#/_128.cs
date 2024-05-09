using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LeetCode
{
    public class _128
    {
        public int LongestConsecutive(int[] nums)
        {
            Dictionary<int, int> dic = new Dictionary<int, int>();

            foreach (int n in nums)
            {
                if (dic.ContainsKey(n)) continue;
                dic.Add(n, 1);
            }

            int max = 0;
            foreach (int n in nums)
            {
                int k = n - 1;
                while (dic.ContainsKey(k))
                {
                    dic[n]++;
                    dic[k] = dic[k + 1] - 1;
                    k--;
                }
                max = Math.Max(max, dic[n]);
            }
            return max;
        }
    }
}

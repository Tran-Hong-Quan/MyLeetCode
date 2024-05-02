using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LeetCode
{
    public class _1_TwoSum
    {
        public int[] TwoSum(int[] nums, int target)
        {
            Dictionary<int, List<int>> dic = new Dictionary<int, List<int>>();
            int[] res = { -1, -1 };

            for (int i = 0; i < nums.Length; i++)
            {
                if (dic.ContainsKey(nums[i]))
                {
                    dic[nums[i]].Add(i);
                }
                else
                {
                    dic.Add(nums[i], new List<int>() { i });
                }
            }

            for (int i = 0; i < nums.Length; i++)
            {
                var key = target - nums[i];

                if (dic.ContainsKey(key))
                {
                    if (nums[i] != key)
                    {
                        res[0] = i;
                        res[1] = dic[key][0];
                        return res;
                    }
                    else
                    {
                        var locs  = dic[key];
                        for (int j = 0; j < locs.Count; j++)
                        {
                            if (locs[j] != i)
                            {
                                res[0] = i;
                                res[1] = locs[j];
                                return res;
                            }
                        }
                    }
                }
            }

            return res;
        }

        public static void Test()
        {
            var s = new _1_TwoSum();
            int[] n = { 3, 2, 4 };
            int t = 6;
            int[] r = s.TwoSum(n, t);
            Console.WriteLine(r[0] + " " + r[1]);
        }
    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LeetCode
{
    public class _16
    {
        public int ThreeSumClosest(int[] nums, int target)
        {
            int res = int.MaxValue;

            Array.Sort(nums);

            for (int i = 0; i < nums.Length - 2; i++)
            {
                int l = i + 1;
                int r = nums.Length - 1;
                while (l < r)
                {
                    int s = nums[l] + nums[r] + nums[i];

                    if (s == target)
                    {
                        return s;
                    }
                    else if (s < target)
                    {
                        l++;
                    }
                    else
                    {
                        r--;
                    }

                    int dis = Math.Abs(s - target);
                    if (dis < Math.Abs(res - target))
                    {
                        res = s;
                    }
                }
            }
            return res;
        }
    }
}

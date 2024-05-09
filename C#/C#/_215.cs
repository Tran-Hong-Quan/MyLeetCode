using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LeetCode
{
    public class _215
    {
        public int FindKthLargest(int[] nums, int k)
        {
            Array.Sort(nums);
            return nums[nums.Length - k];
        }
    }
}

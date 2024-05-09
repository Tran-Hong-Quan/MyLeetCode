using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LeetCode
{
    public class _18
    {
        public IList<IList<int>> FourSum(int[] nums, int target)
        {
            Array.Sort(nums);
            IList<IList<int>> res = new List<IList<int>>();

            for (int i = 0; i < nums.Length - 3; i++)
            {
                if (i > 0 && nums[i] == nums[i - 1]) continue;
                for (int j = i + 1; j < nums.Length - 2; j++)
                {
                    if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                    int l = j + 1;
                    int r = nums.Length - 1;

                    while (l < r)
                    {
                        int s = nums[l] + nums[r] + nums[i] + nums[j];
                        if (s == target)
                        {
                            res.Add(new List<int>()
                            {
                                nums[i],nums[j],nums[l],nums[r]
                            });

                            l++;
                            r--;
                            while (l < r && nums[l] != nums[l - 1]) l++;
                            while (l < r && nums[r] != nums[r - 1]) r--;
                        }
                        else if (s < target)
                        {
                            l++;
                        }
                        else
                        {
                            r--;
                        }
                    }
                }
            }

            return res;
        }

    }
}

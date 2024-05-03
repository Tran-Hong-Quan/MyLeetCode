using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LeetCode
{
    public class _15_3Sum
    {
        public IList<IList<int>> ThreeSum(int[] nums)
        {
            IList<IList<int>> res = new List<IList<int>>();

            Array.Sort(nums);

            for (int i = 0; i < nums.Length; i++)
            {
                int l = i + 1;
                int r = nums.Length - 1;

                if (i > 0 && nums[i] == nums[i - 1])
                {
                    continue;
                }


                while (l < r)
                {
                    int s = nums[i] + nums[r] + nums[l];

                    if (s == 0)
                    {
                        res.Add(new List<int>() { nums[i], nums[r], nums[l] });
                        l++;;
                        while (l < r && nums[l] == nums[l - 1])
                        {
                            l++;
                        }

                        r--;
                        while (l < r && nums[r] == nums[r + 1])
                        {
                            r--;
                        };
                    }
                    else if (s > 0)
                    {
                        r--;
                    }
                    else if (s < 0)
                    {
                        l++;
                    }
                }
            }
            return res;
        }

        public static void Test()
        {
            // Nhập mảng nums
            int[] nums = new int[] { -1, 0, 1, 2, -2 };

            // Gọi hàm ThreeSum và nhận kết quả
            IList<IList<int>> triplets = new _15_3Sum().ThreeSum(nums);

            // In kết quả
            foreach (IList<int> triplet in triplets)
            {
                Console.WriteLine($"{triplet[0]} {triplet[1]} {triplet[2]}");
            }
        }
    }
}

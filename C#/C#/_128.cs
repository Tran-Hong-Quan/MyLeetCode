
namespace C_
{
    internal class _128
    {

        public int LongestConsecutive(int[] nums)
        {
            Dictionary<int, int> map = new Dictionary<int, int>();

            if (nums.Length == 0) return 0;

            foreach(int num in nums) 
            {
                if (!map.ContainsKey(num))
                {
                    map.Add(num, 1);
                }
            }
            int maxVal = 1;
            foreach(var n in map.Keys) 
            {
                int k = n - 1;
                while (map.ContainsKey(k))
                {
                    if (map[k] != 1)
                    {
                        map[n] = map[k] + n - k;
                        break;
                    }
                    map[n]++;
                    map[k] = map[k + 1] - 1;
                    k--;
                }
                maxVal = Math.Max(maxVal, map[n]);
            }
            return maxVal;

        }
    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LeetCode
{
    public class _14_LongestCommonPrefix
    {
        public string LongestCommonPrefix(string[] strs)
        {
            StringBuilder res = new StringBuilder();

            int i = 0;
            while (i < strs[0].Length)
            {
                char cc = strs[0][i];

                foreach(var s in strs)
                {
                    if (s == strs[0]) continue;

                    if (i >= s.Length) return res.ToString();
                    if (s[i] != cc) return res.ToString();
                }
                res.Append(cc);
                i++;
            }

            return res.ToString();
        }

        public static void Test()
        {
            var s = new _14_LongestCommonPrefix();
            string[] strs = { "flower", "flow", "flight" };
            Console.WriteLine(s.LongestCommonPrefix(strs));
        }
    }
}

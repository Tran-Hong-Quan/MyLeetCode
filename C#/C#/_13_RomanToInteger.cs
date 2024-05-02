using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LeetCode
{
    public class _13_RomanToInteger
    {
        public int RomanToInt(string s)
        {
            Dictionary<char, int> dic = new Dictionary<char, int>() {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

            int res = 0;

            res += dic[s[0]];
            for (int i = 1; i < s.Length; i++)
            {
                if (dic[s[i]] <= dic[s[i - 1]])
                {
                    res += dic[s[i]];
                }
                else
                {
                    res -= dic[s[i-1]]*2;
                    res += dic[s[i]];
                }
            }

            return res;
        }

        public static void Test()
        {
            var s = new _13_RomanToInteger();
            Console.WriteLine(s.RomanToInt("MCMXCIV"));
        }
    }
}

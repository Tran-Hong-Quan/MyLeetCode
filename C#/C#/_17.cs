using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LeetCode
{
    public class _17
    {
        IList<string> res = new List<string>();
        Dictionary<int, string> dic = new Dictionary<int, string>()
        {
            {2,"abc" },
            {3,"def" },
            {4,"ghi" },
            {5,"jkl" },
            {6,"mno" },
            {7,"pqrs" },
            {8,"tuv" },
            {9,"wxyz" },
        };
        string digits;
        public IList<string> LetterCombinations(string digits)
        {
            if (digits.Length == 0) return res;

            this.digits = digits;
            BackTracking("", 0);

            return res;
        }

        private void BackTracking(string currentString, int index)
        {
            if (index == digits.Length)
            {
                res.Add(currentString);
                return;
            }

            var s = dic[digits[index] - '0'];

            for (int i = 0; i < s.Length; i++)
            {
                BackTracking(currentString + s[i], index + 1);
            }
        }
    }
}

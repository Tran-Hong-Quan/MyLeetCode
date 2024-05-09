using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LeetCode
{
    public class _881
    {
        public int NumRescueBoats(int[] people, int limit)
        {
            Array.Sort(people);

            int r = people.Length - 1;
            int l = 0;
            int boat = 0;

            while (l <= r)
            {
                if (people[r] == limit || people[l] + people[r] > limit || r == l)
                {
                    boat++;
                    r--;
                }
                else if (people[l] + people[r] <= limit)
                {
                    l++;
                    r--;
                    boat++;
                }
            }

            return boat;
        }
        public static void Test()
        {
            var s = new _881();
            int[] n = { 1, 2 };
            int l = 3;

            Console.WriteLine(s.NumRescueBoats(n, l));
        }

    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LeetCode
{
    public class _165_CompareVersionNumbers
    {
        public int CompareVersion(string version1, string version2)
        {
            string[] v1 = version1.Split('.');
            string[] v2 = version2.Split(".");

            int x = -1, y = -1;
            while (x < v1.Length -1 || y < v2.Length - 1)
            {
                if (x < v1.Length - 1)
                    x++;
                if (y < v2.Length - 1)
                    y++;

                if (x == y)
                {
                    int v1v = int.Parse(v1[x]);
                    int v2v = int.Parse(v2[x]);
                    if (v1v > v2v)
                    {
                        return 1;
                    }
                    if (v1v < v2v)
                    {
                        return -1;
                    }
                }
                else
                {
                    if (x > y)
                    {
                        if (int.Parse(v1[x]) > 0)
                            return 1;
                    }
                    if (x < y)
                    {
                        if (int.Parse(v2[y]) > 0)
                            return -1;
                    }
                }
            }

            return 0;
        }

        public static void Test()
        {
            var sl = new _165_CompareVersionNumbers();
            Console.WriteLine(sl.CompareVersion("1.0.1", "1"));
        }
    }
}

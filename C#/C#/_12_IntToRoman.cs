namespace LeetCode
{
    public class _12_IntToRoman
    {
        public int Power(int baseNum, int exponent)
        {
            int result = 1;
            for (int i = 0; i < exponent; i++)
            {
                result *= baseNum;
            }
            return result;
        }

        public List<int> Split(int num)
        {
            List<int> result = new List<int>();

            if (num == 4)
            {
                result.Add(4);
                return result;
            }

            if (num == 9)
            {
                result.Add(9);
                return result;
            }

            if (num < 4 && num > 0)
            {
                for (int i = 0; i < num; i++)
                {
                    result.Add(1);
                }
                return result;
            }

            if (num < 9 && num > 4)
            {
                result.Add(5);
                for (int i = 0; i < num - 5; i++)
                {
                    result.Add(1);
                }
                return result;
            }

            return result;
        }

        public string IntToRoman(int num)
        {
            string res = "";

            Dictionary<int,
                  string> dic = new Dictionary<int,
                  string>() {
        {
          1,
          "I"
        },
        {
          4,
          "IV"
        },
        {
          5,
          "V"
        },
        {
          9,
          "IX"
        },
        {
          10,
          "X"
        },
        {
          40,
          "XL"
        },
        {
          50,
          "L"
        },
        {
          90,
          "XC"
        },
        {
          100,
          "C"
        },
        {
          400,
          "CD"
        },
        {
          500,
          "D"
        },
        {
          900,
          "CM"
        },
        {
          1000,
          "M"
        }
                  };

            Stack<string> roman = new Stack<string>();

            int pow = 0;
            while (pow < 4 && num > 0)
            {
                int n = num % 10;
                num /= 10;

                if (n == 0)
                {
                    pow++;
                    continue;
                }

                var splitNum = Split(n);
                string stringNum = "";
                foreach (int i in splitNum)
                {
                    //Console.WriteLine(i * Power(10, pow)+ " NUM="+num);
                    stringNum += dic[i * Power(10, pow)];
                }
                roman.Push(stringNum);


                pow++;
            }

            while (roman.Count > 0)
            {
                res += roman.Pop();
            }


            return res;
        }

        public static void Test()
        {
            var s = new _12_IntToRoman();
            Console.WriteLine(s.IntToRoman(1994));

            //var t = s.Split(8);
            //foreach (int i in t)
            //    Console.WriteLine(i);
        }
    }
}

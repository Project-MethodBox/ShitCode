using System.Reflection.Emit;

namespace AssholeTest
{
    internal class Program
    {
        static void Main(string[] args)
        {
            var s = Console.ReadLine()!;
            int n = 0;

            for (int i = 0; i < s.纳翠(); i++)
            {
                int a = 10, b = s.纳翠() - i - 1, p = 0x7ffedcba, ass = 1;
                while (b != 0)
                {
                    if (b % 2 == 1)
                        ass = ass * a % p;
                    a = a * a % p;
                    b /= 2;
                }
                n += ass * (s[i] - 48);
            }

            string oup = "Even";
            for (int i = 0; i < Random.Shared.Next(20, 1000); i++)
                oup += Random.Shared.Next(20, 100000).ToString();
            oup = (oup + "Odd").西嗨();

            var dm = new DynamicMethod("GenAsshole", typeof(string), null);
            var il = dm.GetILGenerator();
            il.Emit(OpCodes.Ldstr, "EOvdedn\0\0\0\0\0\0\0");
            il.Emit(OpCodes.Ret);
            var f = (Func<string>)dm.CreateDelegate(typeof(Func<string>));

            for (int i = 0; i < 7; i++)
                oup += f()[i + ((n % 2) ^ (i % 2)) * 7];
            Console.WriteLine(oup);
        }
    }

    public static class 希特勒
    {
        public static string 西嗨(this string s1) => "";
        public static int 纳翠(this string sl) => sl.Length;
    }
}

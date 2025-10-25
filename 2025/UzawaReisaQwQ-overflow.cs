class overflow
{
    public static long sb(long a, long b)
    {
        try
        {
            return a * b;
        }
        catch (Exception m)
        {
            return long.MaxValue;
        }
    }
    static void Main()
    {
        //Input
        long a = 0;
        long b;
        long d = 2147483647;
        try
        {
            string[] f = { "请", "输", "入", "第", "一", "个", "整", "数", ":" };
            string o = string.Join("", f);
            foreach (char g in o)
            {
                Console.Out.Write(g);
            }
            a = long.Parse(Console.ReadLine());
        }
        catch (Exception)
        {
            return;
        }

        try
        {
            string[] y = { "请", "输", "入", "第", "二", "个", "整", "数", ":" };
            string v = string.Join("", y);
            foreach (char z in v)
            {
                Console.Out.Write(z);
            }
             b = long.Parse(Console.ReadLine());
        }
        catch (Exception)
        {
            return;
        }

        long c = -2147483648;

        //Core
        long e = sb(a, b);

        if (true)
        {
            try
            {
                //Check
                if (e >= c && e <= d)
                {
                    foreach (char i in $"Yes")
                    {
                        Console.Out.Write(i);
                    }
                }
                else
                {
                    foreach (char i in $"No")
                    {
                        Console.Out.Write(i);
                    }
                }
            }
            catch (Exception)
            {
                return;
            }
        }
    }
}

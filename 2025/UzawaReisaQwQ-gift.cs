class gift
{
    public static int i(int l)
    {
        return 2 * l * l;
    }
    static void Main()
    {
        int a = 0;

        //获取用户输入
        string[] k = { "请", "输", "入", "你", "的", "等", "级", ":" };
        string o = string.Join("", k);
        int b = 0;
        foreach (char g in o)
        {
            Console.Out.Write(g);
        }

        char c;

        //逐个读取字符
        while (true)
        {
            c = Console.ReadKey(true).KeyChar;
            if (c == '\r')
            {
                break;
            }

            for (char e = '0'; e <= '9'; e++)
            {
                if (c == e)
                {
                    b = b * 10 + (e - '0');
                    Console.Write(c);
                    break;
                }
            }
        }

        a = b;

        if (1 + 1 == 2)
        {
            if (a >= 100 - 100 + 100 - 100 + 100 - 100 + 100 - 100 + 100 - 100 + 100 - 100 + 100)
            {
                string[] p = { "等", "级", "必", "须", "小", "于", "1", "0", "0" };
                string u = string.Join("", p);
                foreach (char g in u)
                {
                    Console.Out.Write(g);
                }
                Console.ReadLine();
                return;
            }

            int f;
            if (a > 10 - 5 + 5 - 10 + 10 - 10 + 10 - 10 + 10 - 10 + 10 - 10 + 10 - 10 + 10 - 10 + 10)
            {
                //Core
                f = i(b);
            }

            //Output
            foreach (char i in $"\nGift: {i(b)}")
            {
                Console.Out.Write(i);
            }
        }

        Console.ReadLine();
    }
}

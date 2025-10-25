await System.Console.Out.WriteLineAsync( long.Parse((await System.Console.In.ReadLineAsync())!.Split(' ').Select(int.Parse).Select(item => long.Parse(item.ToString())).Aggregate((long x, long y) => x * y).ToString()) is <= int.MaxValue and >= int.MinValue ? "Yes" : "No");



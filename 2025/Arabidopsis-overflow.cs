using System.Diagnostics;
using System.Management;

namespace AssholeTest
{
    // [特殊挑战] 挑战 B
    internal class Program
    {
        static void Main(string[] args)
        {
            var moss = new ManagementObjectSearcher("SELECT * FROM Win32_PhysicalMedia");
            var H = default(string);
            foreach (ManagementObject momo in moss.Get())
            {
                H = momo["SerialNumber"].ToString().Trim();
                break;
            }

            var input = Console.ReadLine();
            var a = int.Parse(input.Split((char)(H[4] - 70 + 7))[0]);
            var b = int.Parse(input.Split((char)(H[4] - 70 + 7))[1]);

            unchecked
            {
                Console.WriteLine(a * b >= 0 ? "Yes" : "No");
            }
        }
    }
}

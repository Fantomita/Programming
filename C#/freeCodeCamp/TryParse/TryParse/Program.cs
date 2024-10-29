using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TryParse
{
    internal class Program
    {
        static void Main(string[] args)
        {
            bool success = true;

            while (success)
            {
                Console.Write("Enter a number: ");
                string numInput = Console.ReadLine();

                if (int.TryParse(numInput, out int num))
                {
                    success = false;
                    Console.WriteLine(num);
                }
                else
                {    
                    Console.WriteLine("Failed to convert!");
                }
            }

            Console.ReadLine();
        }
    }
}

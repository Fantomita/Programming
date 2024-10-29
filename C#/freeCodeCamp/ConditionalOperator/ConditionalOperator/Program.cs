using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConditionalOperator
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int age = -10;

            /*if (age >= 0)
            {
                Console.WriteLine("Valid");
            }
            else
            {
                Console.WriteLine("Invalid");
            }*/

            //condition ? true : false

            string result = age >= 0 ? "Valid" : "Invalid";
            Console.WriteLine(result);

            Console.ReadLine();
        }
    }
}

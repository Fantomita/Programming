using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleIO
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //Console.WriteLine("Hello my name is Vlad!");

            Console.Write("Enter your name: ");
            string name = Console.ReadLine();
            //Console.WriteLine(name + " is your name!");

            Console.Write("Enter your age: ");
            //string ageInput = Console.ReadLine();
            //int age = Convert.ToInt32(ageInput);
            int age = Convert.ToInt32(Console.ReadLine());
            //Console.WriteLine(age + " is your age!");

            //Console.Write("Your name is ");
            //Console.Write(name);
            //Console.Write(" and yout age is ");
            //Console.Write(age);

            Console.WriteLine();
            Console.WriteLine("Your name is " + name + " and your age is " +  age);

            Console.ReadLine();
        }
    }
}

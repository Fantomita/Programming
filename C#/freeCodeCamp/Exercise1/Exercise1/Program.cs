using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Exercise1
{
    internal class Program
    {
        /*
            * Define a variable to hold your name
            * Define a variable to hould your phone number
            * Define a variable to hold your age
            * Print variables line-by-line to the screen 
            * Extra: define variables using the var keyword
        */
        static void Main(string[] args)
        {
            string name = "Vlad",
                   phoneNumber = "0746615423";
            int age = 18;

            Console.WriteLine(name);
            Console.WriteLine(phoneNumber);
            Console.WriteLine(age);


            Console.ReadLine();
        }
    }
}

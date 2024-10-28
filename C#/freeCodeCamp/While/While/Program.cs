using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization.Formatters;
using System.Text;
using System.Threading.Tasks;

namespace While
{
    internal class Program
    {
        static void Main(string[] args)
        {
            /*for (int i = 0; i < 10; ++i)
            {
                Console.WriteLine(i);
            }

            int i = 0;
            while (i < 10)
            {
                Console.WriteLine(i);
                i++;
            }*/

            Console.Write("Enter the first number: ");
            int numberA = Convert.ToInt32(Console.ReadLine());

            Console.Write("Enter the second number: ");
            int numberB = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine();

            int actualAnswer = numberA * numberB;
            int answer = 0;

            Console.Write("Whats the value of " + numberA + " x " + numberB + "?");
            Console.WriteLine();

            /*while (answer != actualAnswer)
            {
                Console.Write("Enter your answer: ");
                answer = Convert.ToInt32(Console.ReadLine());

                if (answer != actualAnswer)
                {
                    Console.WriteLine("Close but it was wrong!");
                    Console.WriteLine();
                }
            }*/

            do
            {
                Console.Write("Enter your answer: ");
                answer = Convert.ToInt32(Console.ReadLine());

                if (answer != actualAnswer)
                {
                    Console.WriteLine("Close but it was wrong!");
                    Console.WriteLine();
                }
            } while (answer != actualAnswer);

            Console.WriteLine("Well done!");

            Console.ReadLine();
        }
    }
}

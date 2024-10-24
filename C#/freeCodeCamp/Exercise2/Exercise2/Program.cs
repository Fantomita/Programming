using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Exercise2
{
    /*
     * Create & initialise two ints
     * Make a variable to work out the remainder
     * Output remainder to the screen
     * Change the first int variable to another number
        * and recalculate the remainder
        * output new remainder to the screen
     */
    internal class Program
    {
        static void Main(string[] args)
        {
            int firstNumber = 123,
                secondNumber = 24,
                remainder = firstNumber % secondNumber;
            Console.WriteLine(remainder);

            firstNumber = 4534;
            remainder = firstNumber % secondNumber;
            Console.WriteLine(remainder);

            Console.ReadLine();
        }
    }
}

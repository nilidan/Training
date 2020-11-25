using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace StopWatch
{
    class Program
    {

        public class Stopwatch
        {
            DateTime startTime;
            Boolean start;
            DateTime stopTime;

            public void Start()
            {
                if (start)
                {
                    throw new InvalidOperationException("Cannot start: already running");
                }
                Console.WriteLine("\n**Start**\n");
                startTime = DateTime.Now;
                start = true;
            }

            public void Stop()
            {
                if (!start)
                {
                    throw new InvalidOperationException("Cannot stop: not running");
                }
                Console.WriteLine("\n**Stop**\n");
                start = false;
                stopTime = DateTime.Now;
            }

            public TimeSpan ElaspedTime()
            {
                if (start)
                {
                    return DateTime.Now - startTime;
                }
                else
                {
                    return stopTime - startTime;
                }
            }
        }
        static void Main(string[] args)
        {

             var stopwatch = new Stopwatch();
             int choice;
             int a;
             Boolean num;

                do
                {
                Console.Write("Stopwatch Program \nEnter your choice below \n");
                Console.Write(" 1-Start Timer \n 2-Stop Timer \n 3-Read Timer \n 0-Quit \n");

                       
                num = int.TryParse(Console.ReadLine(),out a);

                if(num)
                {
                    choice = a;
                }
                else
                {
                    choice = 5;
                }
                    switch (choice)
                    {
                        case 1: stopwatch.Start();
                                break;
                        case 2: stopwatch.Stop();
                                break;
                        case 3: Console.WriteLine(stopwatch.ElaspedTime());
                                Console.WriteLine();
                                break;
                        default:Console.WriteLine("Invalid Input \n");
                        break;
                    }

                } while (choice != 0);
            
        }
    }
}

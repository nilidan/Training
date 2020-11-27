using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DatabaseConnectionInheritanceAndPolymorphism
{
    public class SqlConnection: DbConnection
    {

        SqlConnection(string myString) : base(myString) { }

        public override void openConnect()
        {
            Console.WriteLine("Opening Connection");
        }

        public override void closeConnect()
        {
            Console.WriteLine("Closing Connection");
        }
    }

    public class OracleConnection : DbConnection
    {

        OracleConnection(string myString) : base(myString) { }

        public override void openConnect()
        {
            Console.WriteLine("Opening Connection");
        }

        public override void closeConnect()
        {
            Console.WriteLine("Closing Connection");
        }
    }
    class Program
    {
        static void Main(string[] args)
        {

            try
            {
                Console.WriteLine("Hello");
            }
            catch (ArgumentException e)
            {
                Console.WriteLine("{0}: {1}", e.GetType().Name, e.Message);
            }
        }
    }
}

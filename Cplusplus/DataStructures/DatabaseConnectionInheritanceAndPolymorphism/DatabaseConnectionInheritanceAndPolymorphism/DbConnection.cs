using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DatabaseConnectionInheritanceAndPolymorphism
{
    public abstract class DbConnection
    {
        public string connectionString { get; set; }
        public TimeSpan time { get; set; }

        public DbConnection( string connectionString)
        {
            if (!string.IsNullOrEmpty(connectionString))
            {
                this.connectionString = connectionString;
            }
            else
            {
                throw new ArgumentException("Name cannot be null or empty string");
            }
        }


        public abstract void openConnect();
        public abstract void closeConnect();
    }
}

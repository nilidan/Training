using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SOLIDPrinciples
{
    class Program
    {
        static void Main(string[] args)
        {
           //  Demo_SRP srp = new Demo_SRP() ;
          //  srp.S_Demo();

            Demo_OCP ocp = new Demo_OCP();

            ocp.OC_Demo();
 

        }
    }
}

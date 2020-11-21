using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace StackProgram
{
    class Stack {


       private LinkedList<object> list = new LinkedList<object>();

      public  void Push(object obj)
        {
            list.AddLast(obj);
        }
       public object Pop()
        {
            object o = list.Last.Value;

            list.RemoveLast();

            return o;
        }


      public  void Clear()
        {
            list.Clear();
        }


    }

    class Program
    {
        static void Main(string[] args)
        {
            var stack = new Stack();
            stack.Push(1);
            stack.Push(2);
            stack.Push(3);
            Console.WriteLine(stack.Pop());
            Console.WriteLine(stack.Pop());
            Console.WriteLine(stack.Pop());
        }
    }
}

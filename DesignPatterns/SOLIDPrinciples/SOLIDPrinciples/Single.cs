using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;

namespace SOLIDPrinciples
{
    // just stores a couple of journal entries and ways of
    // working with them
    /* Demonstrates Single Responsibility Principle, 
     * Any class should have a single responsibility to change*/
    public class Journal
    {
        private readonly List<string> entries = new List<string>();

        private static int count = 0;

        public int AddEntry(string text)
        {
            entries.Add($"{++count}: {text}");
            return count; // memento pattern!
        }

        public void RemoveEntry(int index)
        {
            entries.RemoveAt(index);
        }

        public override string ToString()
        {
            return string.Join(Environment.NewLine, entries); //joins all the strings together
        }

        // breaks single responsibility principle because the class is now responsible for whole bunch of things
        // For the persistance of objects we break it down to another class called Persistance
       /* public void Save(string filename, bool overwrite = false)
        {
            File.WriteAllText(filename, ToString());
        }

        public void Load(string filename)
        {

        }

        public void Load(Uri uri)
        {

        }*/
    }

    // handles the responsibility of persisting objects the Save to File
    // Now the Journal is only handling the entries and Persistance class is handling the Saving
    public class Persistence
    {
        public void SaveToFile(Journal journal, string filename, bool overwrite = false)
        {
            if (overwrite || !File.Exists(filename))
                File.WriteAllText(filename, journal.ToString());
        }

     
    }

    public class Demo_SRP
    {
        public void S_Demo()
        {
            var j = new Journal();
            j.AddEntry("I cried today.");
            j.AddEntry("I ate a bug.");
            WriteLine(j);

          //  var p = new Persistence();
         //   var filename = @"c:\temp\journal.txt";
          //  p.SaveToFile(j, filename);
          //  Process.Start(filename);
        }
    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Map.view
{
    class TextMenu
    {
        private Dictionary<String, Command> commands;

        public TextMenu()
        {
            commands = new Dictionary<string, Command>();
        }

        public void addCommand(Command c)
        {
            commands.Add(c.key, c);
        }

        private void printMenu()
        {
            foreach(Command c in commands.Values)
            {
                Console.WriteLine("{0} : {1}", c.key, c.description);
            }
        }

        public void show()
        {
            while(true)
            {
                printMenu();
                Console.Write("Enter option: ");
                String key = Console.ReadLine();
                Command c = commands[key];
                if (c == null)
                    Console.WriteLine("Invalid option!");
                else
                    c.execute();
            }
        }
    }
}

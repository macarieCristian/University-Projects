using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Map.view
{
    class ExitCommand : Command
    {
        public ExitCommand(string k, string desc) : base(k, desc) { }

        public override void execute()
        {
            Environment.Exit(0);
        }
    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Map.controller;

namespace Map.view
{
    class RunExample : Command
    {
        private Controller ctrl;

        public RunExample(string k, string desc, Controller c) : base(k, desc)
        {
            ctrl = c;
        }

        public override void execute()
        {
            try
            {
                ctrl.allSteps();
            }
            catch(Exception e)
            {
                Console.WriteLine(e.Message);
            }
        }
    }
}

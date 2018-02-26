using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Map.view
{
    public abstract class Command
    {
        public String key { get; }
        public String description{get;}

        public Command(String k, String desc)
        {
            key = k;
            description = desc;
        }

        public abstract void execute();

    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Map.domain
{
    public class FileIDGenerator
    {
        private static int id = 0;
        static public int generateId() { return id++; }
    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Map.domain
{
    public class FileData
    {
        public String filePath { get; set; }
        public StreamReader sr { get; set; }

        public FileData(String path, StreamReader s)
        {
            filePath = path;
            sr = s;
        }

        public override string ToString()
        {
            String[] file = filePath.Split('\\');
            return " " + file[file.Length - 1] + " ";
        }
    }
}

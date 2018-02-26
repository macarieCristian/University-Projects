using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Map.domain;
using System.IO;

namespace Map.repository
{
    class Repository : IRepository
    {
        private ProgramState ps;
        private String fileName;

        public Repository(String filePath)
        {
            this.fileName = filePath;
        }

        public ProgramState Program
        {
            get
            {
                return ps;
            }

            set
            {
                ps = value;
            }
        }

        public void logPrgStateExec()
        {
            try
            {
                using (StreamWriter pw = File.AppendText(fileName))
                {
                    pw.WriteLine("ExeStack:");
                    pw.WriteLine(ps.exeStack);
                    pw.WriteLine("SymTable:");
                    pw.WriteLine(ps.symbolTable);
                    pw.WriteLine("Out:");
                    pw.WriteLine(ps.outList);
                    pw.WriteLine("FileTable:");
                    pw.WriteLine(ps.fileTable);
                    pw.WriteLine("---------------------------------------------------------------");
                }
            }
            catch(IOException e)
            {
                throw new Exception(e.Message);
            }
        }
    }
}

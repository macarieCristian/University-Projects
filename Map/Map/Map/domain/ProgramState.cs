using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Map.statement;

namespace Map.domain
{
    public class ProgramState
    {
        public IStack<IStatement> exeStack { get; }
        public IDict<String,int> symbolTable { get; set; }
        public ILis<int> outList { get; set; }
        public IDict<int,FileData> fileTable { get; set; }
        public IStatement originalPrg { get; set; }

        public ProgramState(IStack<IStatement> stack,
                            IDict<String,int> symb,
                            ILis<int> outl,
                            IDict<int,FileData> files,
                            IStatement original)
        {
            exeStack = stack;
            symbolTable = symb;
            outList = outl;
            fileTable = files;
            originalPrg = original;
        }

        public override string ToString()
        {
            StringBuilder sb = new StringBuilder();
            sb.Append("\n   Execution stack:  " + exeStack + "\n");
            sb.Append("   Symbol Table:  " + symbolTable + "\n");
            sb.Append("   Output List:   " +outList +"\n");
            sb.Append("   FileTable:   " + fileTable + "\n");
            sb.Append("   Original program:   " + originalPrg + "\n");
            return sb.ToString();
        }
    }
}

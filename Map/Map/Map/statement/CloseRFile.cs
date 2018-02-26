using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Map.domain;
using Map.expression;
using System.IO;

namespace Map.statement
{
    class CloseRFile : IStatement
    {
        private IExpression exprFileId;

        public CloseRFile(IExpression fileid)
        {
            exprFileId = fileid;
        }

        private bool exists(ProgramState p, int id)
        {
            if (p.fileTable.contains(id))
                return true;
            return false;
        }

       
        public ProgramState execute(ProgramState ps)
        {
            try
            {
                int id = exprFileId.eval(ps.symbolTable);
                if (!exists(ps, id))
                    throw new Exception("Cannot close a file which does not exist!");
                StreamReader br = ps.fileTable.getValue(id).sr;
                br.Close();
                ps.fileTable.remove(id);
            }
            catch (IOException e)
            {
                throw new Exception(e.Message);
            }

            return null;
        }

       
        public override String ToString()
        {
            return "Close(" + exprFileId + ")";
        }
    }
}

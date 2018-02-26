using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Map.domain;
using System.IO;
using Map.expression;

namespace Map.statement
{
    class ReadFile : IStatement
    {
        private IExpression exprFileId;
        private String varName;

        public ReadFile(IExpression expr, String varn)
        {
            exprFileId = expr;
            varName = varn;
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
                    throw new Exception("The file does not exist!");
                StreamReader br = ps.fileTable.getValue(id).sr;
                int result;
                String line = br.ReadLine();
                if (line == null || line.Equals(""))
                    result = 0;
                else
                    result = Int32.Parse(line.Trim());
                if (ps.symbolTable.contains(varName))
                    ps.symbolTable.update(varName, result);
                else
                    ps.symbolTable.add(varName, result);
            }
            catch (IOException e)
            {
                throw new Exception(e.Message);
            }
            return null;
        }

        
        public override String ToString()
        {
            return "ReadFile(" + varName + ")";
        }
    }
}

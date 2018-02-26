using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Map.domain;

namespace Map.expression
{
    public interface IExpression
    {
        int eval(IDict<String, int> symbolTable);
    }
}

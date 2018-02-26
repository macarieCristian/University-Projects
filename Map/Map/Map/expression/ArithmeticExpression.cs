using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Map.domain;

namespace Map.expression
{
    class ArithmeticExpression : IExpression
    {
        private char oper;
        private IExpression ex1;
        private IExpression ex2;

        public ArithmeticExpression(char o,IExpression e1,IExpression e2)
        {
            oper = o;
            ex1 = e1;
            ex2 = e2;
        }

        public int eval(IDict<string, int> symbolTable)
        {
            int left = ex1.eval(symbolTable);
            int right = ex2.eval(symbolTable);
            if (oper == '+')
                return left + right;
            if (oper == '-')
			return left - right;
            if (oper == '*')
			return left * right;
            if (oper == '/')
		{
                if (right == 0)
                    throw new Exception("Division by 0!");
                return left / right;
            }
            throw new Exception("Wrong operator!");
        }

        public override string ToString()
        {
            return ex1.ToString() + oper + ex2.ToString();
        }
    }
}

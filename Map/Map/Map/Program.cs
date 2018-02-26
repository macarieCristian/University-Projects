using Map.domain;
using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Map.expression;
using Map.statement;
using Map.repository;
using Map.controller;
using Map.view;

namespace Map
{
    class Program
    {
        static void Main(string[] args)
        {
            IStack<IStatement> stack = new ExeStack<IStatement>();
            IDict<String, int> dictionary = new SymbTable<String, int>();
            ILis<int> outL = new OutList<int>();
            IDict<int, FileData> fileTab = new FileTable<int, FileData>();


            IStatement stm1 = new AssignStatement("a", new ArithmeticExpression('+', new ConstExpression(5), new ConstExpression(4)));
            IStatement stm2 = new CompStatement(new AssignStatement("a", new ArithmeticExpression('+', new ConstExpression(5), new ConstExpression(4))), new AssignStatement("b", new ArithmeticExpression('-', new ConstExpression(14), new ConstExpression(4))));


            IStatement asgnVar = new AssignStatement("x", new ArithmeticExpression('-', new ConstExpression(50), new ConstExpression(49)));
            IStatement ifstm = new IfStatement(new VarExpression("x"), new AssignStatement("x", new ConstExpression(13)), new AssignStatement("x", new ConstExpression(10)));
            IStatement stm3 = new CompStatement(asgnVar, new CompStatement(ifstm, new PrintStatement(new VarExpression("x"))));

            IStatement stm4 = new CompStatement(new OpenRFile("file", @"c:\users\cristian\documents\visual studio 2015\Projects\Map\Map\ex1.txt"), new CompStatement(new ReadFile(new VarExpression("file"), "x"), new CloseRFile(new VarExpression("file"))));
            IStatement stm5 = new CompStatement(new OpenRFile("file", @"c:\users\cristian\documents\visual studio 2015\Projects\Map\Map\ex1.txt"), new CompStatement(new ReadFile(new VarExpression("file"), "x"), new CompStatement(new ReadFile(new VarExpression("file"), "y"), new CloseRFile(new VarExpression("file")))));




            stack.push(stm5);

            ProgramState ps = new ProgramState(stack, dictionary, outL, fileTab, stm5);
            IRepository repo = new Repository(@"c:\users\cristian\documents\visual studio 2015\Projects\Map\Map\OutLog.txt");
            repo.Program = ps;

            Controller ctrl = new Controller(repo);

            TextMenu menu = new TextMenu();
            menu.addCommand(new ExitCommand("0", "exit."));
            menu.addCommand(new RunExample("1", "Run Program.", ctrl));

            menu.show();


            Console.ReadKey();
        }
    }
}

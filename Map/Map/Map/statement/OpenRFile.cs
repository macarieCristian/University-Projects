using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Map.domain;
using System.IO;

namespace Map.statement
{
    public class OpenRFile : IStatement
    {
        private String varFile, filePath;
        private String fileName;

        public OpenRFile(String varf, String path)
        {
            varFile = varf;
            filePath = path;
            String[] file = filePath.Split('\\');
            fileName = file[file.Length - 1];
        }

        private bool exists(ProgramState ps, String path)
        {
            foreach (int k in ps.fileTable.getAll())
                if (ps.fileTable.getValue(k).filePath.Equals(path))
                    return true;
            return false;
        }

        public ProgramState execute(ProgramState ps)
        {
            if (exists(ps, filePath))
                throw new Exception("The file " + filePath + " is already opened!");
            try
            {
                StreamReader sr = File.OpenText(filePath);

                FileData fd = new FileData(filePath, sr);
                int id = FileIDGenerator.generateId();
                ps.fileTable.add(id, fd);
                if (ps.symbolTable.contains(varFile))
                    ps.symbolTable.update(varFile, id);
                else
                    ps.symbolTable.add(varFile, id);
            }
            catch(IOException e)
            {
                throw new Exception(e.Message);
            }
            return null;
        }

        public override string ToString()
        {
            return "Openfile(" + varFile + "," + fileName + ") ";
        }
    }
}

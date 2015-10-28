using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;

using System.IO.MemoryMappedFiles;
using System.IO;

namespace HJ_MakeRoute
{
    static class Program
    {
        /// <summary>
        /// アプリケーションのメイン エントリ ポイントです。
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new MakeRouteForm());
        }
    }

    class SharedMemory
    {
        String FILEMAPNAME;
        MemoryMappedFile mmf;

        public SharedMemory(String str)
        {
            FILEMAPNAME = str;
            mmf = MemoryMappedFile.CreateNew(FILEMAPNAME, 10000);
        }

        ~SharedMemory()
        {
            mmf.Dispose();
        }

        public virtual Int32 getShMemData(int offset)
        {
            using (MemoryMappedViewStream stream = mmf.CreateViewStream())
            {
                BinaryReader reader = new BinaryReader(stream);
                for (int i = 0; i < offset; i++ )   reader.ReadInt32();
                return reader.ReadInt32();
            }
        }
        public virtual void setShMemData(Int32 data, int offset)
        {
            using (MemoryMappedViewStream stream = mmf.CreateViewStream())
            {
                BinaryWriter writer = new BinaryWriter(stream);
                writer.Seek(offset*sizeof(Int32),SeekOrigin.Begin);
                writer.Write(data);
            }
        }

    }

}

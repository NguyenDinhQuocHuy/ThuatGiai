using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab04_Bai01_D
{
    public class Node
    {
        public SinhVien Data { get; set; } // Du lieu
        public Node Next { get; set; }     // Con tro
        public Node (SinhVien sv)
        {
            Data = sv;
            Next = null;
        }
    }
}

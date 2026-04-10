using System;
using System.Collections.Generic;
using System.Linq;

namespace DoThiChung
{
    public class DoThi
    {
        private List<List<int>> a; // Ma trận kề (lưu số cạnh)
        private int soDinh;
        private bool coHuong; // true = có hướng, false = vô hướng

        public DoThi(int n, bool coHuong)
        {
            this.soDinh = n;
            this.coHuong = coHuong;
            a = new List<List<int>>();
            for (int i = 0; i < n; i++)
                a.Add(Enumerable.Repeat(0, n).ToList());
        }

        // Thêm đỉnh mới
        public void ThemDinh()
        {
            soDinh++;
            foreach (var row in a)
                row.Add(0);
            a.Add(Enumerable.Repeat(0, soDinh).ToList());
            Console.WriteLine("Da them dinh {0}.", soDinh - 1);
        }

        // Xóa đỉnh (và các cạnh liên quan)
        public void XoaDinh(int dinh)
        {
            if (dinh < 0 || dinh >= soDinh)
            {
                Console.WriteLine("Dinh khong hop le!");
                return;
            }
            a.RemoveAt(dinh);               // xóa hàng
            foreach (var row in a)
                row.RemoveAt(dinh);         // xóa cột
            soDinh--;
            Console.WriteLine("Da xoa dinh {0}", dinh);
        }

        // Thêm cạnh
        public void ThemCanh(int u, int v)
        {
            if (u < 0 || v < 0 || u >= soDinh || v >= soDinh)
            {
                Console.WriteLine("Dinh khong hop le!");
                return;
            }
            a[u][v]++;
            if (!coHuong && u != v) a[v][u]++; // vô hướng thì đối xứng
            Console.WriteLine("Da them canh ({0}, {1})", u, v);
        }

        // Xóa cạnh
        public void XoaCanh(int u, int v)
        {
            if (u < 0 || v < 0 || u >= soDinh || v >= soDinh)
            {
                Console.WriteLine("Dinh khong hop le!");
                return;
            }
            if (a[u][v] > 0)
            {
                a[u][v]--;
                if (!coHuong && u != v) a[v][u]--;
                Console.WriteLine("Da xoa 1 canh giua ({0}, {1})", u, v);
            }
            else Console.WriteLine("Khong ton tai canh giua ({0}, {1})", u, v);
        }

        // In ma trận kề
        public void InMaTran()
        {
            Console.WriteLine("\nMa tran ke ({0} dinh):", soDinh);
            Console.Write("    ");
            for (int i = 0; i < soDinh; i++) Console.Write("{0,3}", i);
            Console.WriteLine();
            for (int i = 0; i < soDinh; i++)
            {
                Console.Write("{0,3} ", i);
                for (int j = 0; j < soDinh; j++)
                    Console.Write("{0,3}", a[i][j]);
                Console.WriteLine();
            }
        }
    }
}

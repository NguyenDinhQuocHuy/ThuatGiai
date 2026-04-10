using System;
using System.Collections.Generic;
using System.IO;

namespace Nhom2_DanhSachLienKet_Linklist
{
    public class DanhSachSinhVien
    {
        private LinkedList<SinhVien> ds = new LinkedList<SinhVien>();

        // 1. Nhap danh sach tu file CSV
        public void LoadFile(string filename)
        {
            ds.Clear();
            var lines = File.ReadAllLines(filename);
            foreach (var line in lines)
            {
                if (!string.IsNullOrWhiteSpace(line))
                    ds.AddLast(new SinhVien(line));
            }
        }

        // Copy
        public void Copy(DanhSachSinhVien a)
        {
            this.ds.Clear();
            foreach (var sv in a.ds)
            {          
                this.ds.AddLast(new SinhVien(sv.MaSV, sv.Ho, sv.TenLot, sv.Ten, sv.NamSinh, sv.DiemTB));
            }
        }


        // Header
        public void XuatTieuDe()
        {
            Console.WriteLine($"{"MaSV",-10}{"Ho",-10}{"TenLot",-15}{"Ten",-10}{"NamSinh",-8}{"DiemTB",-5}");
            Console.WriteLine(new string('-', 60));
        }

        // 2. Xem danh sach
        public void XuatDanhSach()
        {
            if (ds.Count == 0)
            {
                Console.WriteLine("Danh sach rong");
                return;
            }

            XuatTieuDe();
            foreach (var sv in ds)
                sv.Xuat1SinhVien();
        }

        // 3. Them SV vao dau
        public void ThemDau(SinhVien sv)
        {
            ds.AddFirst(sv);
        }

        // 4. Xoa theo ma
        public void XoaTheoMa(string ma)
        {
            var node = ds.First;
            while (node != null)
            {
                if (node.Value.MaSV == ma)
                {
                    ds.Remove(node);
                    Console.WriteLine("Da xoa");
                    return;
                }
                node = node.Next;
            }
            Console.WriteLine("Khong tim thay");
        }

        // 5. Tim kiem tuyen tinh
        public void TimTheoHoTenVaNamSinh(string ho, string ten, int namsinh)
        {
            bool found = false;
            foreach (var sv in ds)
            {
                if (sv.Ho == ho && sv.Ten == ten && sv.NamSinh < namsinh)
                {
                    if (!found)
                    {
                        XuatTieuDe();
                        found = true;
                    }
                    sv.Xuat1SinhVien();
                }
            }
            if (!found)
                Console.WriteLine("Khong co sinh vien thoa man dieu kien");
        }

        // 6. Tim kiem tuyen tinh linh canh tra ve index dau tien theo Ten
        public int TimKiemTuyenTinhLinhCanh(string ten)
        {
            SinhVien a = new SinhVien();
            a.Ten = ten;                         // Tạo phần tử lính canh
            ds.AddLast(a);

            int i = 0;
            var p = ds.First;
            while (p.Value.Ten != ten)
            {
                i++;
                p = p.Next;
            }

            ds.RemoveLast();                            // Xóa phần tử lính canh

            if (p.Value == a) return -1;
            return i;
        }


        // 7. Sap xep doi cho truc tiep theo nam sinh (tang dan)
        public void SapXepTangTheoNamSinh()
        {
            for (var p = ds.First; p != null; p = p.Next)
            {
                for (var q = p.Next; q != null; q = q.Next)
                {
                    if (p.Value.NamSinh > q.Value.NamSinh)
                    {
                        // Hoan vi
                        var temp = p.Value;
                        p.Value = q.Value;
                        q.Value = temp;
                    }
                }
            }
        }
    }
}

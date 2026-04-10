
using System;

namespace Nhom2_DanhSachLienKet_Linklist
{
    internal class Program
    {
        static void Main(string[] args)
        {
            DanhSachSinhVien ds = new DanhSachSinhVien();
            DanhSachSinhVien tam = new DanhSachSinhVien();
            int chon;

            do
            {
            repeat:
                Console.Clear();
                XuatMenu();
                Console.Write("Nhap chon: ");
                chon = int.Parse(Console.ReadLine());
                Console.WriteLine();

                switch (chon)
                {
                    case 1:
                        Console.Clear();
                        ds.LoadFile("data.txt");
                        Console.WriteLine("Da load file xong");
                        break;

                    case 2:
                        ds.XuatDanhSach();
                        break;

                    case 3:
                        Console.WriteLine("Nhap 1 sinh vien theo format: ma,ho,tenlot,ten,namsinh,diemtb");
                        string s = Console.ReadLine();
                        SinhVien sv = new SinhVien(s);
                        ds.ThemDau(sv);
                        Console.WriteLine("Da them vao dau danh sach");
                        break;

                    case 4:
                        Console.Write("Nhap ma SV muon xoa: ");
                        string ma = Console.ReadLine();
                        ds.XoaTheoMa(ma);
                        break;

                    case 5:
                        Console.Write("Nhap ho: ");
                        string ho = Console.ReadLine();
                        Console.Write("Nhap ten: ");
                        string ten = Console.ReadLine();
                        Console.Write("Nhap nam sinh x: ");
                        int x = int.Parse(Console.ReadLine());
                        ds.TimTheoHoTenVaNamSinh(ho, ten, x);
                        break;

                    case 6:
                        Console.Write("Nhap ten muon tim: ");
                        string t = Console.ReadLine();
                        int kq = ds.TimKiemTuyenTinhLinhCanh(t);
                        if (kq == -1)
                            Console.WriteLine("Khong tim thay sinh vien co ten {0}!", t);
                        else
                            Console.WriteLine("Vi tri: " + kq);
                            break;

                    case 7:
                        Console.WriteLine("Ban dau: ");
                        ds.XuatDanhSach();
                        tam.Copy(ds);
                        tam.SapXepTangTheoNamSinh();
                        Console.WriteLine("Da sap xep xong, danh sach sau khi sap xep: ");
                        tam.XuatDanhSach();
                        break;

                    default:
                        Console.WriteLine("Thoat chuong trinh");
                        break;
                }

                if (chon > 0)
                {
                    Console.ReadKey();
                    goto repeat;
                }
                
            }
            while (chon < 0 || chon > 7);
        }

        static void XuatMenu()
        {
            Console.WriteLine("===== MENU =====");
            Console.WriteLine("1. Nhap du lieu tu file data.txt");
            Console.WriteLine("2. Xem danh sach sinh vien");
            Console.WriteLine("3. Them sinh vien vao dau danh sach");
            Console.WriteLine("4. Xoa sinh vien theo ma so");
            Console.WriteLine("5. Tim tat ca sinh vien trung ho ten va nam sinh < x");
            Console.WriteLine("6. Tim kiem tuyen tinh linh canh theo Ten");
            Console.WriteLine("7. Sap xep tang dan theo nam sinh (Doi cho truc tiep)");
            Console.WriteLine("0. Thoat");
        }
    } 
}

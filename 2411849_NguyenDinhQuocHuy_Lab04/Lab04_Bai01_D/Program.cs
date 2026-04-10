using System;
using Lab04_Bai01_D;

class Program
{ 
    static void Main(string[] args)
    {
        Console.WriteLine("--- PHAN 1: KIEM TRA DSLK DON TU XAY DUNG ---");
        MySinglyLinkedList ds1 = new MySinglyLinkedList();
        ds1.ThemCuoi(new SinhVien("SV01", "An", 8.0));
        ds1.ThemCuoi(new SinhVien("SV02", "Binh", 7.5));
        ds1.ThemCuoi(new SinhVien("SV03", "Cuong", 9.0));

        ds1.XuatDanhSach(); // Xuat 3 SV
        Console.WriteLine("Thuc hien xoa SV2...");
        ds1.Xoa("SV02");

        ds1.XuatDanhSach(); // Xuat 2 SV (An, Cuong)

        Console.WriteLine("Thuc hien xoa SV01 (Xoa dau)...");
        ds1.Xoa("SV01");
        ds1.XuatDanhSach();

        Console.WriteLine("\nNhan phim bat ky de tiep tuc...");
        Console.ReadKey();
    }
}


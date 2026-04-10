using System;
using Lab05_Bai01_IntHashTable;

class Program
{
    static void Main(string[] args)
    {
        IntHashTable ds = new IntHashTable();
        int chon;
        do
        {
            Console.Clear();
            Menu();
            Console.Write("Chon chuc nang: ");

            if (!int.TryParse(Console.ReadLine(), out chon)) chon = -1;

            switch (chon)
            {
                case 1:
                    Console.Write("Nhap ten file (Test1.txt / Test2.txt): ");
                    string tenFile = Console.ReadLine();
                    ds.DocFile(tenFile);
                    break;
                case 2: ds.XemDanhSach(); break;
                case 3: Console.WriteLine("Min: " + ds.TimMin()); break;
                case 4: Console.WriteLine("Max: " + ds.TimMax()); break;
                case 5:
                    Console.Write("Nhap gia tri x can dem: ");
                    int x = int.Parse(Console.ReadLine());
                    Console.WriteLine($"So {x} xuat hien {ds.DemX(x)} lan.");
                    break;
                case 6: Console.WriteLine("Tong: " + ds.TinhTong()); break;
                case 7: Console.WriteLine("Tong (khong trung): " + ds.TongKhacNhau()); break;
                case 8: ds.XuatTanSuat(); break;
                case 9:
                    ds.SapXepChen();
                    ds.XemDanhSach();
                    break;
                case 10:
                    ds.SapXepTuyChinh();
                    ds.XemDanhSach();
                    break;
                case 11: ds.XuLySoNguyenTo(); break;
                case 0: Console.WriteLine("Tam biet!"); break;
                default: Console.WriteLine("Chon sai, vui long chon lai!"); break;
            }

            if (chon > 0)
            {
                Console.WriteLine("Nhan 1 phim bat ky de tiep tuc...");
                Console.ReadKey();
            }

        } while (chon != 0);
    }

    static void Menu()
    {
        Console.WriteLine("\n--- MENU ---");
        Console.WriteLine("1. Tao danh sach (Doc file Test1.txt hoac Test2.txt)");
        Console.WriteLine("2. Xem danh sach");
        Console.WriteLine("3. Tim Min");
        Console.WriteLine("4. Tim Max");
        Console.WriteLine("5. Dem so lan xuat hien cua x");
        Console.WriteLine("6. Tinh tong");
        Console.WriteLine("7. Tinh tong cac gia tri khac nhau");
        Console.WriteLine("8. Xuat tan suat cac phan tu");
        Console.WriteLine("9. Sap xep tang dan (Insertion Sort)");
        Console.WriteLine("10. Sap xep: 0 dau -> Am giam -> Duong tang");
        Console.WriteLine("11. So nguyen to va tong cua chung");
        Console.WriteLine("0. Thoat");
    }
}

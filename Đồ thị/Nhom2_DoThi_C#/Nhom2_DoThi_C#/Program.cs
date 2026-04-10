using System;
using DoThiChung;

class Program
{
    static void Main()
    {
        Console.OutputEncoding = System.Text.Encoding.UTF8;

        Console.Write("Nhap so dinh ban dau: ");
        int n = int.Parse(Console.ReadLine() ?? "0");

        Console.Write("Do thi co huong? (y/n): ");
        bool coHuong = Console.ReadLine()?.ToLower() == "y";

        DoThi g = new DoThi(n, coHuong);

        while (true)
        {
            Console.WriteLine("\n===== MENU =====");
            Console.WriteLine("1. Thêm đỉnh");
            Console.WriteLine("2. Xóa đỉnh");
            Console.WriteLine("3. Thêm cạnh");
            Console.WriteLine("4. Xóa cạnh");
            Console.WriteLine("5. In ma trận kề");
            Console.WriteLine("0. Thoát");
            Console.Write("Chọn: ");
            int chon = int.Parse(Console.ReadLine());

            switch (chon)
            {
                case 1:
                    g.ThemDinh();
                    break;
                case 2:
                    Console.Write("Nhập đỉnh cần xóa: ");
                    g.XoaDinh(int.Parse(Console.ReadLine() ?? "0"));
                    break;
                case 3:
                    Console.Write("Nhập 2 đỉnh u v: ");
                    var input = Console.ReadLine()?.Split(' ');
                    g.ThemCanh(int.Parse(input[0]), int.Parse(input[1]));
                    break;
                case 4:
                    Console.Write("Nhập 2 đỉnh u v: ");
                    input = Console.ReadLine()?.Split(' ');
                    g.XoaCanh(int.Parse(input[0]), int.Parse(input[1]));
                    break;
                case 5:
                    g.InMaTran();
                    break;
                case 0:
                    return;
                default:
                    Console.WriteLine("Thoat chuong trinh!");
                    break;
            }
        }
    }
}

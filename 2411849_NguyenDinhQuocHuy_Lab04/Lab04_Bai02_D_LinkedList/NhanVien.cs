using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;

namespace Lab04_Bai02_D_LinkedList
{
    public class NhanVien
    {
        public string MaNV { get; set; }
        public string HoTen { get; set; }
        public string PhongBan {  get; set; }
        public DateTime NgayVaoLam { get; set; }
        public double LuongCoBan {  get; set; }

        public NhanVien() { }

        public void XuatThongTin()
        {
            Console.WriteLine($"| {MaNV,-7} | {HoTen,-25} | {PhongBan,-15} | {NgayVaoLam,-12: dd/MM/yyyy} | {LuongCoBan,15:N0} VND |");
        }
    }
}

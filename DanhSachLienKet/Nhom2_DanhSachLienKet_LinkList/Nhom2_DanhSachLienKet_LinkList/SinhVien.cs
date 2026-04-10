using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Nhom2_DanhSachLienKet_Linklist
{
    public class SinhVien
    {
        public string MaSV;
        public string Ho;
        public string TenLot;
        public string Ten;
        public int NamSinh;
        public float DiemTB;

        public SinhVien() { }

        public SinhVien(string line)
        {
            var t = line.Split(',');
            MaSV = t[0];
            Ho = t[1];
            TenLot = t[2];
            Ten = t[3];
            NamSinh = int.Parse(t[4]);
            DiemTB = float.Parse(t[5]);
        }

        public SinhVien(string ma, string ho, string tenlot, string ten, int namsinh, float dtb)
        {
            MaSV = ma;
            Ho = ho;
            TenLot = tenlot;
            Ten = ten;
            NamSinh = namsinh;
            DiemTB = dtb;
        }


        public void Xuat1SinhVien()
        {
            Console.WriteLine($"{MaSV,-10}{Ho,-10}{TenLot,-15}{Ten,-10}{NamSinh,-8}{DiemTB,-5}");
        }
    }
}


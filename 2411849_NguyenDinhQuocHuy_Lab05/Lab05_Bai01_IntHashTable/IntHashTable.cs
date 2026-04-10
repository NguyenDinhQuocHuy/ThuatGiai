using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab05_Bai01_IntHashTable
{
    public class IntHashTable
    {
        private Hashtable bangBam;
        private int soLuong;

        public IntHashTable()
        {
            bangBam = new Hashtable();
            soLuong = 0;
        }

        // Doc file
        public void DocFile(string tenFile)
        {
            bangBam.Clear();
            soLuong = 0;

            if (!File.Exists(tenFile))
            {
                Console.WriteLine("File khong ton tai!");
            }

            try
            {
                using (StreamReader sr = new StreamReader(tenFile))
                {
                    string line;
                    while ((line = sr.ReadLine()) != null)
                    {
                        string[] s = line.Split(new char[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries);
                        foreach (string i in s)
                        {
                            if (int.TryParse(i, out int giaTri))
                            {
                                bangBam.Add(soLuong, giaTri);
                                soLuong++;
                            }
                        }
                    }
                }
                Console.WriteLine("Doc file thanh cong!");
            }

            catch(Exception ex)
            {
                Console.WriteLine("Loi khi doc file: " + ex.Message);
            }
        }

        // Xem danh sach
        public void XemDanhSach()
        {
            Console.WriteLine("Danh sach: ");
            for (int i = 0; i < soLuong; i++)
            {
                Console.Write(bangBam[i] + " ");
            }
            Console.WriteLine();
        }

        // Giá trị nhỏ nhất
        public int TimMin()
        {
            if (soLuong == 0) return 0;
            int min = (int)bangBam[0];
            for (int i = 1; i < soLuong; i++)
            {
                int val = (int)bangBam[i];
                if (val < min) min = val;
            }
            return min;
        }

        // Giá trị lớn nhất
        public int TimMax()
        {
            if (soLuong == 0) return 0;
            int max = (int)bangBam[0];
            for (int i = 1; i < soLuong; i++)
            {
                int val = (int)bangBam[i];
                if (val > max) max = val;
            }
            return max;
        }

        // Đếm số lần xuất hiện của x
        public int DemX(int x)
        {
            int dem = 0;
            for (int i = 0; i < soLuong; i++)
            {
                if ((int)bangBam[i] == x) dem++;
            }
            return dem;
        }

        // 6. Tính tổng
        public long TinhTong()
        {
            long tong = 0;
            for (int i = 0; i < soLuong; i++)
            {
                tong += (int)bangBam[i];
            }
            return tong;
        }

        // Tổng các giá trị khác nhau (Mỗi giá trị chỉ cộng 1 lần)
        public long TongKhacNhau()
        {
            Hashtable tempCheck = new Hashtable(); 
            long tong = 0;

            for (int i = 0; i < soLuong; i++)
            {
                int val = (int)bangBam[i];
                if (!tempCheck.ContainsKey(val))
                {
                    tong += val;
                    tempCheck.Add(val, true); 
                }
            }
            return tong;
        }

        // Xuat gia tri khac nhau va tan suat
        public void XuatTanSuat()
        {
            Hashtable tanSuat = new Hashtable(); // Key: Số, Value: Số lần xuất hiện

            for (int i = 0; i < soLuong; i++)
            {
                int val = (int)bangBam[i];
                if (tanSuat.ContainsKey(val))
                {
                    tanSuat[val] = (int)tanSuat[val] + 1;
                }
                else
                {
                    tanSuat.Add(val, 1);
                }
            }

            Console.WriteLine("Gia tri | So lan xuat hien");
            foreach (DictionaryEntry item in tanSuat)
            {
                Console.WriteLine($"   {item.Key,-4} | {item.Value}");
            }
        }

        // Sap xep tang dan bang chen truc tiep
        public void SapXepChen()
        {
            for (int i = 1; i < soLuong; i++)
            {
                int key = (int)bangBam[i];
                int j = i - 1;

                // Di chuyển các phần tử lớn hơn key về sau
                while (j >= 0 && (int)bangBam[j] > key)
                {
                    bangBam[j + 1] = bangBam[j];
                    j = j - 1;
                }
                bangBam[j + 1] = key;
            }
            Console.WriteLine("Da sap xep tang dan bang Insertion Sort.");
        }

        // Sap xep
        public void SapXepTuyChinh()
        {
            List<int> zeros = new List<int>();
            List<int> negatives = new List<int>();
            List<int> positives = new List<int>();

            
            for (int i = 0; i < soLuong; i++)
            {
                int val = (int)bangBam[i];
                if (val == 0) zeros.Add(val);
                else if (val < 0) negatives.Add(val);
                else positives.Add(val);
            }

            
            negatives.Sort((a, b) => b.CompareTo(a)); 
            positives.Sort(); 

            
            int index = 0;
            foreach (int x in zeros) bangBam[index++] = x;
            foreach (int x in negatives) bangBam[index++] = x;
            foreach (int x in positives) bangBam[index++] = x;

            Console.WriteLine("Da sap xep: 0 -> Am giam -> Duong tang.");
        }

        // 11. Số nguyên tố
        private bool IsPrime(int n)
        {
            if (n < 2) return false;
            for (int i = 2; i <= Math.Sqrt(n); i++)
                if (n % i == 0) return false;
            return true;
        }

        public void XuLySoNguyenTo()
        {
            Console.Write("Cac so nguyen to: ");
            long tongSNT = 0;
            bool coSNT = false;

            for (int i = 0; i < soLuong; i++)
            {
                int val = (int)bangBam[i];
                if (IsPrime(val))
                {
                    Console.Write(val + " ");
                    tongSNT += val;
                    coSNT = true;
                }
            }
            Console.WriteLine();
            if (coSNT) Console.WriteLine("Tong cac so nguyen to: " + tongSNT);
            else Console.WriteLine("Khong co so nguyen to nao!");
        }
    }
}


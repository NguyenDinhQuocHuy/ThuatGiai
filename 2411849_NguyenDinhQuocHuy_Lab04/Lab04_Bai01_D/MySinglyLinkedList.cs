using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab04_Bai01_D
{
    public class MySinglyLinkedList
    {
        private Node head; // Con tro qua trong nhat, qun ly dau danh sach
        public MySinglyLinkedList() 
        {
            head = null;
        }

        // Them cac phuong thuc
        // Them cuoi
        public void ThemCuoi(SinhVien sv)
        {
            Node newNode = new Node(sv);
            if (head == null) 
            { 
                head = newNode; // Neu DS rong
            }

            else
            {
                Node current = head;
                while (current.Next != null) // Duyet den Node cuoi
                {
                    current = current.Next;
                }
                current.Next = newNode; // Moc Node moi vao cuoi
            }
        }

        // Duyet
        public void XuatDanhSach()
        {
            Node current = head;
            while (current != null) 
            {
                Console.WriteLine($"{current.Data.MaSV} - {current.Data.HoTen} - {current.Data.DiemTB}");
                current = current.Next;
            }
        }

        // Xoa theo ma sinh vien
        public bool Xoa(string maSV)
        {
            if (head == null) return false; // DS rong

            // TH1: Xoa ngay dau (Head)
            if (head.Data.MaSV.Equals(maSV))
            {
                head = head.Next;
                return true;
            }

            // TH2: Xoa o giua hoac cuoi
            Node previous = null;
            Node current = head;

            // Tim Node can xoa, 'previous' luon theo sau 'current'
            while (current != null && !current.Data.MaSV.Equals(maSV)) 
            { 
               previous = current;
                current = current.Next;
            }

            // Neu khong tim thay (duyet het danh sach)
            if (current == null) return false;

            // Neu tim thay ('current' la node can xoa)
            // Noi 'previous' voi 'current.Next' (bo qua 'current')
            previous.Next = current.Next;
            return true;
        }
    }
}

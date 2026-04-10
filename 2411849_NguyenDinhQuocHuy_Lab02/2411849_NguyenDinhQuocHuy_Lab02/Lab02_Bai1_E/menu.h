// Khai bao nguyen mau ham
void XuatMenu();
int ChonMenu(int soMenu);
void XuLyMenu(int menu, nhanvien a[MAX], int& n);

// Ham dieu khien
void XuatMenu()
{
	cout << "\n========== HE THONG CHUC NANG ==========";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Tao danh sach sinh vien ";
	cout << "\n2. Xem danh sach sinh vien";
	cout << "\n3. Tim kiem theo ma sinh vien";
	cout << "\n4. Tim kiem theo ten-Xuat cac sinh vien cung ten";
	cout << "\n5. Tim kiem theo ho-Xuat cac sinh vien cung ho";
	cout << "\n6. Xuat sinh vien co diem trung binh >= dtb cho truoc";
	cout << "\n7. Tim kiem theo lop-Xuat danh sach sinh vien trong lop";
	cout << "\n8. Tim kiem nhi phan theo tich luy (neu truong tich luy co thu tu)";
}

int ChonMenu(int soMenu)
{
	int stt;
	for (;;)
	{
		system("cls");
		XuatMenu();
		cout << "\nNhap mot so (0 <= so <= " << soMenu << ") de chon menu, stt = ";
		cin >> stt;
		if (0 <= stt && stt <= soMenu)
			break;
	}
	return stt;
}

void XuLyMenu(int menu, nhanvien a[MAX], int& n)
{

}

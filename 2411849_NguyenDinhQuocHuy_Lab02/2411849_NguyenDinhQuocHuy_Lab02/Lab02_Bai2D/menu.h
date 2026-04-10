// Khai bao nguyen mau ham
void XuatMenu();
int ChonMenu(int soMenu);
void XuLyMenu(int menu, sinhvien a[MAX], int& n);

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

void XuLyMenu(int menu, sinhvien a[MAX], int& n)
{
	int kq;
	char filename[MAX];
	char mssv[10], ten[10], ho[10], lop[6];
	double diemTB;
	switch (menu)
	{
	case 0:
		system("CLS");
		cout << "\n0. Thoat khoi chuong trinh\n";
		break;
	case 1:
		system("CLS");
		cout << "\n1. Tao danh sach sinh vien\n";
		do
		{
			cout << "\nNhap ten tap tin, filename = ";
			cin >> filename;
			kq = TapTin_MangCT(filename, a, n);
		} while (!kq);
		cout << "\nDanh sach sinh vien vua nhap:\n";
		Xuat_DSSV(a, n);
		cout << endl;

		break;
	case 2:
		system("CLS");
		cout << "\n2. Xem Danh sach sinh vien.\n";
		cout << "\nDanh sach sinh vien hien hanh:\n";
		Xuat_DSSV(a, n);
		cout << endl;
		break;
	case 3:
		system("cls");
		cout << "\n3. Tim kiem theo ma sinh vien";
		cout << endl << "Nhap ma so sinh vien: "; cin >> mssv;
		kq = Tim_MaSo_DauTien(mssv, a, n);
		if (kq == -1)
			cout << endl << "Khong co sinh vien nao co ma so " << mssv;
		else
			cout << endl << "Sinh vien co ma so " << mssv << "o vi tri " << kq;
		break;
	case 4:
		system("CLS");
		cout << "\n4. Tim kiem theo ten--Xuat cac sinh vien cung ten\n";
		cout << endl << "Nhap ten sinh vien: "; cin >> ten;
		Tim_TheoTen(ten, a, n);
		break;
	case 5:
		system("CLS");
		cout << "\n5. Tim kiem theo ho--Xuat cac sinh vien cung ho\n";
		cout << endl << "Nhap ho sinh vien: "; cin >> ho;
		Tim_TheoHo(ho, a, n);
		break;
	case 6:
		system("CLS");
		cout << "\n6. Xuat sinh vien co diem trung binh >= dtb cho truoc\n";
		cout << endl << "Nhap diem TB: "; cin >> diemTB;
		Tim_TheoDTB(diemTB, a, n);
		break;
	case 7:
		system("CLS");
		cout << "\n7. Tim kiem theo lop--Xuat cac sinh vien thuoc lop\n";
		cout << endl << "Nhap lop: "; cin >> lop;
		Tim_TheoLop(lop, a, n);
		break;
	case 8:
		system("CLS");
		cout << "\n8. Tim kien nhi phan theo tich luy";
		TKNP_Theo_TichLuy(a, n);
		break;
	}
}
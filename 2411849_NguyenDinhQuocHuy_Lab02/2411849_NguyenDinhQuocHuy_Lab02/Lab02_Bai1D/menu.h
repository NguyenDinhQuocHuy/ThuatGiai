// Khai bao nguyen mau
void XuatMenu();
int ChonMenu(int menu);
void XuLyMenu(int menu, int a[MAX], int& n);


// Ham dieu khien
void XuatMenu()
{
	cout << "\n==================== HE THONG CHUC NANG ====================";
	cout << "\n0. Thoat khoi chong trinh";
	cout << "\n1. Tao du lieu";
	cout << "\n2. Xem du lieu";
	cout << "\n3. Tim kiem tuyen tinh - Tra ve chi so dau tien";
	cout << "\n4. Tim kiem tuyen tinh - Tra ve chi so i dau tien, neu co (Co linh canh)";
	cout << "\n5. Tim kiem tuyen tinh - Tra ve chi so cuoi cung, neu co";
	cout << "\n6. Tra ve tat ca chi so i neu co";
}

int ChonMenu(int soMenu)
{
	int stt;
	for (;;)
	{
		system("cls");
		XuatMenu();
		cout << "\nNhap 1 so (0 <= so <= " <<soMenu<< " ) de chon menu, stt: ";
		cin >> stt;
		if (0 < stt && stt <= soMenu)
			break;
	}
	return stt;
}

void XuLyMenu(int menu, int a[MAX], int& n)
{
	int kq;
	int x;
	char filename[MAX];
	switch (menu)
	{
	case 0:
		system("cls");
		cout << "\n0. Thoat khoi chuong trinh\n";
		break;

	case 1:
		system("cls");
		cout << "\n1. Tao du lieu";
		do
		{
			cout << "\nNhap ten tap tin, file name: ";
			cin >> filename;
			kq = TapTin_mang1c(filename, a, n);
		} while (!kq);
		cout << "\nMang vua tao: \n";
		Xuat_Mang(a, n);
		cout << endl;
		break;

	case 2:
		system("cls");
		cout << "\n2. Xem du lieu";
		cout << "\nMang vua tao: \n";
		Xuat_Mang(a, n);
		cout << endl;
		break;

	case 3:
		cout << "\n3. Tim kiem tuyen tinh - Tra ve chi so dau tien";
		cout << "\nMang du lieu ban dau: \n";
		Xuat_Mang(a, n);
		cout << "\nNhap x: ";
		cin >> x;
		kq = TKTT_DauTien(a, n, x);
		if (kq == -1)
			cout << endl << x << " khong co trong mang";
		else
			cout << endl << x << " xuat hien trong a tai vi tri dau tien la: " << kq;
		cout << endl;
		break;

	case 4:
		cout << "\n4. Tim kiem tuyen tinh (co linh canh) - Tra ve chi so dau tien";
		cout << "\nMang du lieu ban dau: \n";
		Xuat_Mang(a, n);
		cout << "\nNhap x: ";
		cin >> x;
		kq = TKTT_DauTien_LC(a, n, x);
		if (kq == -1)
			cout << endl << x << " khong co trong mang";
		else
			cout << endl << x << " xuat hen trong a tai vi tri dau tien la: " << kq;
		cout << endl;
		break;

	case 5:
		cout << "\n5. Tim kiem tuyen tinh - Tra ve chi so cuoi cung";
		cout << "\nMang du lieu ban dau: \n";
		Xuat_Mang(a, n);
		cout << "\nNhap x: ";
		cin >> x;
		kq = TKTT_CuoiCung(a, n, x);
		if (kq == -1)
			cout << endl << x << " khong co trong mang";
		else
			cout << endl << x << "xuat hien trong a tai vi tri cuoi cng la: " << kq;
		cout << endl;
		break;

	case 6:
		cout << "\n6. Tra ve tat ca chi so i neu co";
		cout << "\nMang du lieu ban dau: \n";
		Xuat_Mang(a, n);
		cout << "\nNhap x: ";
		cin >> x;
		TKTT_CacChiSo(a, n, x);
		cout << endl;
		break;
	}
}
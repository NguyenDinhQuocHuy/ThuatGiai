// Khai bao nguyen mau ham
void XuatMenu();
int ChonMenu(int soMenu);
void XuLyMenu(int menu, NhanVien a[MAX], int& n);

// Ham dieu khien
void XuatMenu()
{
	cout << "\n========== MENU ==========";
	cout << "\n1. Nhap tu file";
	cout << "\n2. Xuat danh sach";
	cout << "\n3. Chon truc tiep sap tang theo MA NV";
	cout << "\n4. Chen truc tiep sap tang theo DIA CHI";
	cout << "\n5. Radix sort tang theo NAM SINH";
	cout << "\n6. Heap sort tang theo LUONG (phu thuoc TEN, HO, NAM SINH)";
	cout << "\n0. Thoat";
}

int ChonMenu(int soMenu)
{
	int stt;
	for (;;)
	{
		system("cls");
		XuatMenu();
		cout << "\nNhap mot so de chon menu, stt = ";
		cin >> stt;
		if (0 <= stt && stt <= soMenu)
			break;
	}
	return stt;
}

void XuLyMenu(int menu, NhanVien a[MAX], int& n)
{
	int kq;
	char filename[MAX];
	double diemTB;
	NhanVien b[MAX];
	switch (menu)
	{
	case 0:
		system("CLS");
		cout << "\n0. Thoat khoi chuong trinh\n";
		break;
	case 1:
		system("CLS");
		cout << "\n1. Tao danh sach nhan vien\n";
		do
		{
			cout << "\nNhap ten tap tin, filename = ";
			cin >> filename;
			kq = File_Array(filename, a, n);
		} while (!kq);
		cout << "\nDanh sach nhan vien vua nhap:\n";
		Output_Arr(a, n);
		cout << endl;
		break;
	case 2:
		system("CLS");
		cout << "\n2. Xem danh sach nhan vien.\n";
		cout << "\nDanh sach nhan vien:\n";
		Output_Arr(a, n);
		cout << endl;
		break;
	case 3:
		system("CLS");
		cout << "\n3. Chon truc tiep sap tang theo MA NV";
		cout << "\nDanh sach nhan vien ban dau: \n";
		Output_Arr(a, n);
		cout << "\nDanh sach sau khi sap xep: \n";
		Copy(b, a, n);
		ChonTrucTiep_MaNV(b, n);
		Output_Arr(b, n);
		break;
	case 4:
		cout << "\n4. Chen truc tiep sap tang theo DIA CHI";
		cout << "\nDanh sach nhan vien ban dau: \n";
		Output_Arr(a, n);
		cout << "\nDanh sach sau khi sap xep: \n";
		Copy(b, a, n);
		ChenTrucTiep_DiaChi(b, n);
		Output_Arr(b, n);
		break;
	case 5:
		cout << "\n5. Radix sort tang theo NAM SINH";
		cout << "\nDanh sach nhan vien ban dau: \n";
		Output_Arr(a, n);
		cout << "\nDanh sach sau khi sap xep: \n";
		Copy(b, a, n);
		Radix_NamSinh(b, n);
		Output_Arr(b, n);
		break;
		
	case 6:
		cout << "\n6. Heap sort tang theo LUONG (phu thuoc TEN, HO, NAM SINH)";
		cout << "\nDanh sach nhan vien ban dau: \n";
		Output_Arr(a, n);
		cout << "\nDanh sach sau khi sap xep: \n";
		Copy(b, a, n);
		HeapSort_Luong(b, n);
		Output_Arr(b, n);
		break;
	}
}

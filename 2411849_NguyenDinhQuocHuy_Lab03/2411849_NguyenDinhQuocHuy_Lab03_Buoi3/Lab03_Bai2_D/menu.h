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
	cout << "\nSap tang danh sach sinh vien theo truong Diem trung binh voi: ";
	cout << "\n3. Quick Sort";
	cout << "\n4. Heap Sort";
	cout << "\n5. Merge Sort";
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
	double diemTB;
	sinhvien b[MAX];
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
			kq = File_Array(filename, a, n);
		} while (!kq);
		cout << "\nDanh sach sinh vien vua nhap:\n";
		Output_Arr(a, n);
		cout << endl;
		break;
	case 2:
		system("CLS");
		cout << "\n2. Xem Danh sach sinh vien.\n";
		cout << "\nDanh sach sinh vien hien hanh:\n";
		Output_Arr(a, n);
		cout << endl;
		break;
	case 3:
		system("CLS");
		cout << "\3. Quick Sort\n";
		cout << "\nDanh sach sinh vien ban dau: \n";
		Output_Arr(a, n);
		Copy(b, a, n);
		cout << "\nDanh sach sinh vien sau khi sap xep: ";
		QuickSort(b, n);
		Output_Arr(b, n);
		break;
	case 4:
		system("CLS");
		cout << "\4. Heap Sort\n";
		cout << "\nDanh sach sinh vien ban dau: \n";
		Output_Arr(a, n);
		Copy(b, a, n);
		cout << "\nDanh sach sinh vien sau khi sap xep: ";
		HeapSort(b, n);
		Output_Arr(b, n);
		break;
	case 5:
		system("CLS");
		cout << "\5. Merge Sort\n";
		cout << "\nDanh sach sinh vien ban dau: \n";
		Output_Arr(a, n);
		Copy(b, a, n);
		cout << "\nDanh sach sinh vien sau khi sap xep: ";
		MergeSort(b, n);
		Output_Arr(b, n);
		break;
	}
}

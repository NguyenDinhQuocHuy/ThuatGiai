void XuatMenu();
int ChonMenu(int soMenu);
void XuLyMenu(int menu, int a[MAX], int& n);

void XuatMenu()
{
	cout << "\n0. Thoat chuong trinh";
	cout << "\n1. Tao du lieu";
	cout << "\n2. Xem du lieu";
	cout << "\n3.Thuat giai Merge Sort";
	cout << "\n4. Thuat giai Heap Sort"; 
	cout << "\n5. Thuat giai Radix Sort"; 
	cout << "\n6. Thuat giai Quick Sort\n"; 
}

int ChonMenu(int soMenu)
{
	int stt;

	for (;;)
	{
		system("cls");
		XuatMenu();
		cout << "\nNhap mot so de chon menu,stt = ";
		cin >> stt;
		if (0 <= stt && stt <= soMenu)
			break;
	}
	return stt;
}

void XuLyMenu(int menu, int a[MAX], int& n)
{
	int kq;
	char filename[MAX];
	int b[MAX];
	switch (menu)
	{
	case 0:
		system("cls");
		cout << "\n0.Thoat khoi chuong trinh\n";
		break;

	case 1:
		system("cls");
		cout << "\nTao du lieu";
		do
		{
			cout << "\nNhap ten tap tin, filename = ";
			cin >> filename;
			kq = File_Array(filename, a, n);
		} while (!kq);
		cout << "\nMang vua tao: \n";
		Output(a, n);
		cout << endl;
		break;

	case 2:
		system("cls");
		cout << "\nXuat du lieu";
		cout << "\nMang vua tao: \n";
		Output(a, n);
		cout << endl;
		break;

	case 3:
		cout << "\n Thuat giai Merge Sort";
		cout << "\nMang du lieu ban dau:\n";
		Output(a, n);
		cout << "Thuat giai: \n";
		MergeSort_Step(a, n);
		break;

	case 4:
		cout << "\n Thuat giai Heap Sort";
		cout << "\nMang du lieu ban dau:\n";
		Output(a, n);
		cout << "Thuat giai: \n";
		HeapSort_Step(a, n);
		break;

	case 5:
		cout << "\n Thuat giai Radix Sort";
		cout << "\nMang du lieu ban dau:\n";
		Output(a, n);
		cout << "Thuat giai: \n";
		Radix_Step(a, n);
		cout << endl;
		break;

	case 6:
		cout << "\nThuat giai Quick Sort";
		cout << "\nMang du lieu ban dau:\n";
		Output(a, n);
		cout << "Thuat giai: \n";
		QuickSort_Step(a, n);
		cout << endl;
		break;
	default:
		return;
	}
}


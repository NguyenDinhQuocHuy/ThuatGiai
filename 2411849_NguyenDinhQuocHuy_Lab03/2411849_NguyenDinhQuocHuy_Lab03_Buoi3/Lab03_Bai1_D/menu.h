void XuatMenu();
int ChonMenu(int soMenu);
void XuLyMenu(int menu, int a[MAX], int& n);

void XuatMenu()
{
	cout << "\n0. Thoat chuong trinh";
	cout << "\n1. Tao du lieu";
	cout << "\n2. Xem du lieu";
	cout << "\n3. Chon truc tiep (Selection Straight sort)";
	cout << "\n4. Chen truc tiep (Insertion Straight sort)";
	cout << "\n5. Doi cho truc tiep (Interchange Straight sort)";
	cout << "\n6. Noi bot (Bubble sort)";
	cout << "\n7. Chen nhi phan (Binary Insertion Sort)";
	cout << "\n8. Radix";
}

int ChonMenu(int soMenu)
{
	int stt;

	for (;;)
	{
		system("cls");
		XuatMenu();
		cout << "\nNhap mot so (0 <= so <= " << soMenu << ") de chon menu,stt = ";
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
		cout << "\n1. Tao du lieu";
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
		cout << "\n2. Xuat du lieu";
		cout << "\nMang vua tao: \n";
		Output(a, n);
		cout << endl;
		break;

	case 3:
		cout << "\n Chon truc tiep (Selection Straight sort)";
		cout << "\nMang du lieu ban dau:\n";
		Output(a, n);
		Copy(b, a, n);
		cout << "\nSau khi sap xep: \n";
		Selection_L(b, n);
		Output(b, n);
		cout << endl;
		break;
	case 4:
		cout << "\n Chen truc tiep (Insertion Straight sort)";

		cout << "\nMang du lieu ban dau:\n";
		Output(a, n);
		Copy(b, a, n);
		cout << "\nSau khi sap xep: \n";
		Insertion_L(b, n);
		Output(b, n);
		cout << endl;
		break;
	case 5:
		cout << "\n Doi cho truc tiep (Interchange Straight sort)";

		cout << "\nMang du lieu ban dau:\n";
		Output(a, n);
		Copy(b, a, n);
		cout << "\nSau khi sap xep: \n";
		Interchange_L(b, n);
		Output(b, n);
		cout << endl;
		break;
	case 6:
		cout << "\n Noi bot (Bubble sort)";

		cout << "\nMang du lieu ban dau:\n";
		Output(a, n);
		Copy(b, a, n);
		cout << "\nSau khi sap xep: \n";
		Bubble_L(b, n);
		Output(b, n);
		cout << endl;
		break;
	case 7:
		cout << "\n7. Chen nhi phan (Binary Insertion Sort)";
		cout << "\nMang du lieu ban dau:\n";
		Output(a, n);
		Copy(b, a, n);
		cout << "\nSau khi sap xep: \n";
		Binary_Insertion(b, n);
		Output(b, n);
		cout << endl;
		break;

	case 8:
		cout << "\n8. Radix";
		cout << "\nMang du lieu ban dau:\n";
		Output(a, n);
		Copy(b, a, n);
		cout << "\nSau khi sap xep: \n";
		Radix(b, n);
		Output(b, n);
		cout << endl;
		break;
	}

}

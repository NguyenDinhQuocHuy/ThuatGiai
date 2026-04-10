void XuatMenu();
int ChonMenu(int soMenu);
void XuLyMenu(int menu, int a[MAX], int& n);

void XuatMenu()
{
	cout << "\n0. Thoat chuong trinh";
	cout << "\n1. Tao du lieu";
	cout << "\n2. Xem du lieu";
	cout << "\n3. Thuat giai Chon Truc tiep - tai moi buoc dua GTNN ve dau mang";
	cout << "\n4. Thuat giai Chon Truc tiep - tai moi buoc dua GTLN ve cuoi mang";
	cout << "\n5. Thuat giai Chon hai dau";
	cout << "\n6. Thuat giai Chen Truc tiep - chen vao day con tang ben trai";
	cout << "\n7. Thuat giai Chen Truc tiep - chen vao day con tang ben phai";
	cout << "\n8. Thuat giai Chen nhi phan ";
	cout << "\n9. Thuat giai Doi cho Truc tiep - tai moi buoc dua GTNN ve dau mang";
	cout << "\n10. Thuat giai Doi cho Truc tiep - tai moi buoc dua GTLN ve cuoi mang";
	cout << "\n11. Thuat giai Buble - tai moi buoc dua GTNN ve dau mang";
	cout << "\n12. Thuat giai Buble - tai moi buoc dua GTLN ve cuoi mang";
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
		cout << "\n Thuat giai Chon Truc tiep - tai moi buoc dua GTNN ve dau mang";
		cout << "\nMang du lieu ban dau:\n";
		Output(a, n);
		cout << "\nSau khi sap xep: ";
		Selection_L(a, n);
		Output(a, n);
		cout << endl;
		break;

	case 4:
		cout << "\n Thuat giai Chon Truc tiep - tai moi buoc dua GTLN ve cuoi mang";
		cout << "\nMang du lieu ban dau:\n";
		Output(a, n);
		cout << "\nSau khi sap xep: ";
		Selection_R(a, n);
		Output(a, n);
		cout << endl;
		break;

	case 5:
		cout << "\n Thuat giai Chon hai dau";
		cout << "\nMang du lieu ban dau:\n";
		Output(a, n);
		cout << "\nSau khi sap xep: ";
		Selection_R_L(a, n);
		Output(a, n);
		cout << endl;
		break;

	case 6:
		cout << "\n Thuat giai Chen Truc tiep - chen vao day con tang ben trai";
		cout << "\nMang du lieu ban dau:\n";
		Output(a, n);
		cout << "\nSau khi sap xep: ";
		Insertion_L(a, n);
		Output(a, n);
		cout << endl;
		break;

	case 7:
		cout << "\n Thuat giai Chen Truc tiep - chen vao day con tang ben phai";
		cout << "\nMang du lieu ban dau:\n";
		Output(a, n);
		cout << "\nSau khi sap xep: ";
		Insertion_R(a, n);
		Output(a, n);
		cout << endl;
		break;

	case 8:
		cout << "\n Thuat giai Chen nhi phan ";
		cout << "\nMang du lieu ban dau:\n";
		Output(a, n);
		cout << "\nSau khi sap xep: ";
		Binary_Insertion(a, n);
		Output(a, n);
		cout << endl;
		break;

	case 9:
		cout << "\n Thuat giai Doi cho Truc tiep - tai moi buoc dua GTNN ve dau mang";
		cout << "\nMang du lieu ban dau:\n";
		Output(a, n);
		cout << "\nSau khi sap xep: ";
		Interchange_L(a, n);
		Output(a, n);
		cout << endl;
		break;

	case 10:
		cout << "\n Thuat giai Doi cho Truc tiep - tai moi buoc dua GTLN ve cuoi mang";
		cout << "\nMang du lieu ban dau:\n";
		Output(a, n);
		cout << "\nSau khi sap xep: ";
		Interchange_R(a, n);
		Output(a, n);
		cout << endl;
		break;

	case 11:
		cout << "\n Thuat giai Buble - tai moi buoc dua GTNN ve dau mang";
		cout << "\nMang du lieu ban dau:\n";
		Output(a, n);
		cout << "\nSau khi sap xep: ";
		Bubble_L(a, n);
		Output(a, n);
		cout << endl;
		break;

	case 12:
		cout << "\n Thuat giai Buble - tai moi buoc dua GTLN ve cuoi mang";
		cout << "\nMang du lieu ban dau:\n";
		Output(a, n);
		cout << "\nSau khi sap xep: ";
		Bubble_R(a, n);
		Output(a, n);
		cout << endl;
		break;
	}

}

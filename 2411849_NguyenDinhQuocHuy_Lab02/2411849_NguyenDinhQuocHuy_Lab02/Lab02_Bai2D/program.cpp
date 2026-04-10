#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>

using namespace std;

#include "thuvien.h"
#include "menu.h"

void ChayChuongTrinh();

int main()
{
	ChayChuongTrinh();
	return 1;
}

void ChayChuongTrinh()
{
	sinhvien a[MAX];
	int soMenu = 9,
		menu,
		n = 0; //so luong sinh vien trong danh sach
	do
	{
		system("cls");
		menu = ChonMenu(soMenu);
		XuLyMenu(menu, a, n);
		system("PAUSE");
	} while (menu > 0);

}
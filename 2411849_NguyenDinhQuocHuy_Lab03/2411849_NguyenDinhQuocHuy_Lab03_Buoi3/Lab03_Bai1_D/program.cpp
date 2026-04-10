#include <string.h>
#include <iostream>
#include <fstream>
#include <iomanip>

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
	int soMenu = 9, menu;
	int a[MAX], n = 0;
	do
	{
		system("cls");
		menu = ChonMenu(soMenu);
		XuLyMenu(menu, a, n);
		system("PAUSE");
	} while (menu > 0);
}
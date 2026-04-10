#include <iostream>
using namespace std;
#include "ThuVien.h"
int main()
{
	int a[] = { 9, 4, 6, 10, 5, 3, 7, 20, 15 };
    // Tính số lượng phần tử của mảng
    int N = sizeof(a) / sizeof(a[0]);

    // In mảng ban đầu
    cout << "Mang ban dau: ";
    printArray(a, N);

    // Gọi hàm sắp xếp
    HeapSort(a, N);

    // In mảng sau khi sắp xếp
    cout << "Mang sau khi sap xep: ";
    printArray(a, N);

    return 0;
}
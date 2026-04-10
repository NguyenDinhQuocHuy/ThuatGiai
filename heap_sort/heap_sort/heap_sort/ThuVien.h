
// Hàm Hoanvi (Swap) còn thiếu
void Hoanvi(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
    // Hoặc dùng: std::swap(a, b); 
}

// Hàm Shift đã được sửa lỗi
void Shift(int a[], int l, int r)
{
    int x, i, j;
    i = l;
    j = 2 * i + 1; // Con trái
    x = a[i];      // Lưu giá trị gốc

    while (j <= r) // Chừng nào con trái còn trong phạm vi
    {
        // Tìm con lớn nhất (so sánh con trái j và con phải j+1)
        if (j < r && a[j] < a[j + 1])
            j = j + 1; // j bây giờ là chỉ số của con lớn nhất

        // Nếu con lớn nhất <= giá trị gốc (x), thì x đã đúng vị trí
        if (a[j] <= x)
            break; // Thoát vòng lặp

        // Ngược lại, nếu con lớn nhất > x
        a[i] = a[j]; // Đẩy con lớn nhất lên vị trí cha (i)
        i = j;       // Di chuyển i xuống vị trí của con lớn nhất
        j = 2 * i + 1; // Tính vị trí con trái mới
    }

    // Đặt giá trị gốc (x) vào vị trí cuối cùng của nó sau khi sàng
    a[i] = x;
}

// Hàm CreateHeap
void CreateHeap(int a[], int N)
{
    int l;
    l = (N - 1) / 2; // Nút không phải lá cuối cùng
    while (l >= 0)
    {
        Shift(a, l, N - 1); // Vun đống con gốc l
        l = l - 1;
    }
}

// Hàm HeapSort
void HeapSort(int a[], int N)
{
    int r;
    CreateHeap(a, N); // 1. Xây dựng Max Heap

    r = N - 1;
    while (r > 0)
    {
        // 2. Đổi chỗ a[0] (lớn nhất) cho a[r] (cuối heap)
        Hoanvi(a[0], a[r]);

        // 3. Giảm kích thước heap
        r = r - 1;

        // 4. Vun lại đống tại gốc 0 với kích thước mới (0 -> r)
        Shift(a, 0, r);
    }
}

// Hàm tiện ích để in mảng ra màn hình
void printArray(int a[], int N)
{
    for (int i = 0; i < N; i++)
    {
        cout << a[i] << " ";
    }
    cout << std::endl;
}
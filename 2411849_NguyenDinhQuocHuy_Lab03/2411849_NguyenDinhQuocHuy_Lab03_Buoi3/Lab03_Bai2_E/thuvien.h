#define MAX 1000


int File_Array(char* filename, int a[MAX], int& n);
void Output(int a[MAX], int n);
void HoanVi(int& a, int& b);
void Copy(int b[MAX], int a[MAX], int n);

void MergeSort_Step(int a[MAX], int n);
void HeapSort_Step(int a[MAX], int n);
void QuickSort_Step(int a[MAX], int n);
void Radix_Step(int a[MAX], int n);


int File_Array(char* filename, int a[MAX], int& n)
{
    ifstream in(filename);
    if (!in)
        return 0;
    in >> n;
    for (int i = 0; i < n; i++)
        in >> a[i];
    in.close();
    return 1;
}

void Output(int a[MAX], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << "\t";
    cout << endl;
}

void HoanVi(int& a, int& b)
{
    int tam = a;
    a = b;
    b = tam;
}

void Copy(int b[MAX], int a[MAX], int n)
{
    for (int i = 0; i < n; i++)
        b[i] = a[i];
}

// QUICK SORT
void Partition_Int(int a[MAX], int l, int r)
{
    int i = l, j = r;
    int x = a[(l + r) / 2];
    do {
        while (a[i] < x) i++;
        while (a[j] > x) j--;
        if (i <= j) {
            HoanVi(a[i], a[j]);
            Output(a, r + 1);
            i++; j--;
        }
    } while (i <= j);
    if (l < j) Partition_Int(a, l, j);
    if (i < r) Partition_Int(a, i, r);
}

void QuickSort_Step(int a[MAX], int n)
{
    int b[MAX];
    Copy(b, a, n);
    Partition_Int(b, 0, n - 1);
    cout << "Mang sau Quick Sort: \n";
    Output(b, n);
}

// HEAP SORT
void Shift_Int(int a[MAX], int l, int r)
{
    int i = l;
    int x = a[i];
    int j = 2 * i + 1;
    while (j <= r)
    {
        if (j < r && a[j] < a[j + 1]) j++;
        if (a[j] <= x) return;
        else {
            a[i] = a[j];
            i = j;
            j = 2 * i + 1;
        }
    }
    a[i] = x;
}

void Create_Heap_Int(int a[MAX], int n)
{
    for (int l = (n - 1) / 2; l >= 0; l--)
        Shift_Int(a, l, n - 1);
}

void HeapSort_Step(int a[MAX], int n)
{
    int b[MAX];
    Copy(b, a, n);
    Create_Heap_Int(b, n);
    cout << "Heap ban dau: \n";
    Output(b, n);
    int r = n - 1;
    while (r > 0)
    {
        HoanVi(b[0], b[r]);
        cout << "Sau khi doi dau-cuoi: \n";
        Output(b, n);
        r--;
        Shift_Int(b, 0, r);
        cout << "Sau khi Shift: \n";
        Output(b, n);
    }
    cout << "Mang sau Heap Sort: \n";
    Output(b, n);
}

// MERGE SORT 
void Merge_Int(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1, n2 = r - m;
    int* L = new int[n1];
    int* R = new int[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
    delete[] L; delete[] R;
}

void MergeSort_Int(int arr[], int l, int r)
{
    if (l < r) {
        int m = (l + r) / 2;
        MergeSort_Int(arr, l, m);
        MergeSort_Int(arr, m + 1, r);
        Merge_Int(arr, l, m, r);
        Output(arr, r + 1);
    }
}

void MergeSort_Step(int a[MAX], int n)
{
    int b[MAX];
    Copy(b, a, n);
    MergeSort_Int(b, 0, n - 1);
    cout << "Mang sau Merge Sort: \n";
    Output(b, n);
}

// RADIX SORT 
void Radix_Step(int a[MAX], int n)
{
    int b[MAX];
    Copy(b, a, n);

    int max = b[0];
    for (int i = 1; i < n; i++)
        if (b[i] > max) max = b[i];

    int exp = 1;
    while (max / exp > 0) {
        int bucket[10][MAX], count[10] = { 0 };

        for (int i = 0; i < n; i++) 
        {
            int digit = (b[i] / exp) % 10;
            bucket[digit][count[digit]++] = b[i];
        }

        int idx = 0;
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < count[i]; j++)
                b[idx++] = bucket[i][j];

        cout << "Sau khi xet hang " << exp << ": \n";
        Output(b, n);
        exp *= 10;
    }

    cout << "Mang sau Radix Sort: \n";
    Output(b, n);
}

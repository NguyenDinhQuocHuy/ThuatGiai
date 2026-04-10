#define MAX 1000

int File_Array(char* filename, int a[MAX], int& n);
void Output(int a[MAX], int n);
void HoanVi(int& a, int& b);
void Selection_L(int a[MAX], int n);
void Selection_R(int a[MAX], int n);
void Selection_R_L(int a[MAX], int n);
void Insertion_L(int a[MAX], int n);
void Insertion_R(int a[MAX], int n);
void Binary_Insertion(int a[MAX], int n);
void Interchange_L(int a[MAX], int n);
void Interchange_R(int a[MAX], int n);
void Bubble_L(int a[MAX], int n);
void Bubble_R(int a[MAX], int n);

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
	int i;
	for (i = 0; i < n; i++)
		cout << a[i] << "\t";
}

void HoanVi(int& a, int& b)
{
	int tam = a;
	a = b;
	b = tam;
}

void Selection_L(int a[MAX], int n)
{
	int i, j, cs_min;
	for (i = 0; i < n - 1; i++)
	{
		cs_min = i;
		for (j = i + 1; j < n; j++)
			if (a[j] < a[cs_min])
				cs_min = j;
		HoanVi(a[i], a[cs_min]);
	}
}

void Selection_R(int a[MAX], int n)
{
	int i, j, cs_max;
	for (i = 0; i < n - 1; i++)
	{
		cs_max = n - 1 - i;
		for (j = n - 2 - i; j >= 0; j--)
			if (a[j] > a[cs_max])
				cs_max = j;
		HoanVi(a[n - 1 - i], a[cs_max]);
	}
}

void Selection_R_L(int a[MAX], int n)
{
	int i, j, cs_min, cs_max;
	for (i = 0; i < n / 2; i++)
	{
		cs_min = i;
		cs_max = n - 1 - i;
		for (j = i; j <= n - 1 - i; j++)
		{
			if (a[j] < a[cs_min])
				cs_min = j;
			if (a[j] > a[cs_max])
				cs_max = j;
		}
		if (cs_min == n - i - 1)
		{
			HoanVi(a[i], a[cs_min]);
			if (cs_max != i) //?
				HoanVi(a[cs_max], a[n - i - 1]);
		}
		else
		{
			HoanVi(a[cs_max], a[n - i - 1]);
			HoanVi(a[i], a[cs_min]);
		}
	}
}

void Insertion_L(int a[MAX], int n)
{
	int i, x, pos;
	for (i = 1; i < n; i++)
	{
		x = a[i];
		for (pos = i - 1; (pos >= 0) && (a[pos] > x); pos--)
			a[pos + 1] = a[pos];
		a[pos + 1] = x;
	}
}

void Insertion_R(int a[MAX], int n)
{
	int i, x, pos;
	for (i = n - 2; i >= 0; i--)
	{
		x = a[i];
		for (pos = i + 1; (pos < n) && (a[pos] < x); pos++)
			a[pos - 1] = a[pos];
		a[pos - 1] = x;
	}
}

void Binary_Insertion(int a[MAX], int n)
{
	int l, r, m;
	int i, j;
	int x;
	for (i = 1; i < n; i++)
	{
		x = a[i]; l = 0; r = i - 1;
		while (l <= r)
		{
			m = (l + r) / 2;
			if (x < a[m])
				r = m - 1;
			else
				l = m + 1;
		}
		for (j = i - 1; j >= l; j--)
			a[j + 1] = a[j];
		a[l] = x;
	}
}

void Interchange_L(int a[MAX], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
			if (a[j] < a[i])
				HoanVi(a[i], a[j]);
	}
}

void Interchange_R(int a[MAX], int n)
{
	int i, j;
	for (j = n - 1; j > 0; j--)
	{
		for (i = 0; i < j; i++)
			if (a[i] > a[j])
				HoanVi(a[i], a[j]);
	}
}

void Bubble_L(int a[MAX], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		for (j = n - 1; j > i; j--)
			if (a[j] < a[j - 1])
				HoanVi(a[j - 1], a[j]);
	}
}

void Bubble_R(int a[MAX], int n)
{
	int i, j;
	for (j = n - 1; j > 0; j--)
	{
		for (i = 0; i < n - 1; i++)
			if (a[i] > a[i + 1])
				HoanVi(a[i + 1], a[i]);
		cout << "\nBuoc " << n - j << " : ";
		Output(a, n);
		cout << "\n";
	}
	cout << "\nCo " << n - 1 << " buoc thuc hien thuat giai.\n";
}

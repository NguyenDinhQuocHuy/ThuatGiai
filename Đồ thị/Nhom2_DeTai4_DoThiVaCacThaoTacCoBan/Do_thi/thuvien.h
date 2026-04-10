class DoThi
{
private:
	vector<vector<int>>a; // Ma tran ke
	int soDinh;		      // So dinh hien co

public:
	// Khoi tao do thi rong/co n dinh
	DoThi(int n = 0)
	{
		soDinh = n;
		a.assign(n, vector<int>(n, 0)); // Khoi tao ma tran nxn toan 0
	}

    // Them dinh
    void ThemDinh() {
        soDinh++;
        for (auto& hang : a)
            hang.push_back(0);          // Them 1 cot moi vao moi hang
        a.push_back(vector<int>(soDinh, 0)); // Them 1 hang moi toan 0
        cout << "Da them dinh " << soDinh - 1 << endl;
    }

 
    // Them canh
    void ThemCanh(int u, int v) 
    {
        if (u < 0 || v < 0 || u >= soDinh || v >= soDinh) {
            cout << "Loi, dinh khong ton tai!\n";
            return;
        }
        a[u][v] = 1;
        a[v][u] = 1; 
        cout << "Da them canh (" << u << ", " << v << ")\n";
    }

    // Xoa canh
    void XoaCanh(int u, int v) {
        if (u < 0 || v < 0 || u >= soDinh || v >= soDinh) {
            cout << "Loi, dinh khong ton tai!\n";
            return;
        }
        a[u][v] = 0;
        a[v][u] = 0;
        cout << "Da xoa canh (" << u << ", " << v << ")!\n";
    }

    // Sua canh
    void SuaCanh(int u, int v, int giaTri) {
        if (u < 0 || v < 0 || u >= soDinh || v >= soDinh) {
            cout << "Loi, dinh khong ton tai!\n";
            return;
        }
        a[u][v] = giaTri;
        a[v][u] = giaTri; 
        cout << "Da sua canh (" << u << ", " << v << ") thanh " << giaTri << endl;
    }

    // In
    void InMaTran() {
        cout << "\nMa tran ke (" << soDinh << " dinh):\n";
        cout << "    ";
        for (int i = 0; i < soDinh; i++)
            cout << setw(3) << i;
        cout << endl;

        for (int i = 0; i < soDinh; i++) {
            cout << setw(3) << i << " ";
            for (int j = 0; j < soDinh; j++)
                cout << setw(3) << a[i][j];
            cout << endl;
        }
    }
};

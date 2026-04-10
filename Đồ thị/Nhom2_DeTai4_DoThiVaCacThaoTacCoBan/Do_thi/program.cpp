#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;
#include "thuvien.h"
int main() 
{
    DoThi G(3);
    cout << endl << "Them canh: " << endl;
    G.ThemCanh(0, 1);
    G.ThemCanh(1, 2);
    G.InMaTran();

    cout << endl << "Xoa canh: " << endl;
    G.XoaCanh(1, 2);
    G.InMaTran();

    cout << endl << "Sua canh: " << endl;
    G.SuaCanh(0, 1, 0);
    G.InMaTran();

    cout << endl << "Them dinh: " << endl;
    G.ThemDinh();
    G.ThemCanh(2, 3);
    G.InMaTran();

}


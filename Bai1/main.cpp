#include <iostream>
#include "NgayThangNam.h"

using namespace std;

int main()
{
    NgayThangNam d;
    d.Nhap();
    d.Xuat();
    cout << endl << "Ngay tiep theo: ";
    d.NgayThangNamTiepTheo();
    return 0;
}

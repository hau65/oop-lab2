#include "Complex.h"
#include <iostream>
using std::runtime_error;
using std::cout;

using namespace std;

int main()
{
    Complex n1, n2;
    cout << "Nhap so thu 1; \n"; n1.Nhap();
    cout << "Nhap so thu 2: \n"; n2.Nhap();
    cout << "-------------\n";
    cout << "So thu nhat: "; n1.Xuat(); cout << " | So thu hai: "; n2.Xuat();
    cout << "\nTong: "; Complex::Tong(n1, n2).Xuat();
    cout << "\nHieu: "; Complex::Hieu(n1, n2).Xuat();
    cout << "\nTich: "; Complex::Tich(n1, n2).Xuat();
    cout << "\nThuong: "; try{Complex::Thuong(n1, n2).Xuat();} catch (const runtime_error& e) {cout << e.what() << "\n";}
    return 0;
}

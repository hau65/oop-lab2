#include "Fraction.h"
#include <iostream>
using std::cout;
using std::runtime_error;

int main()
{
    //INPUT
    Fraction f1, f2;
    cout << "Nhap phan so 1: \n"; f1.Nhap();
    cout << "Nahp phan so 2: \n"; f2.Nhap();

    //OUTPUT
    cout << "\nPS1 : "; f1.Xuat(); cout << " | PS2: "; f2.Xuat();
    cout << "\nPS1 + PS2: "; Fraction::Tong(f1, f2).Xuat();
    cout << "\nPS1 - PS2: "; Fraction::Hieu(f1, f2).Xuat();
    cout << "\nPS1 * PS2: "; Fraction::Tich(f1, f2).Xuat();
    cout << "\nPS1 / PS2: ";
    try{Fraction::Thuong(f1, f2).Xuat();}
    catch(const runtime_error& e)
        {cout << e.what() << "\n";}
    cout << "\n"; Fraction::SoSanh(f1,f2);
    return 0;
}

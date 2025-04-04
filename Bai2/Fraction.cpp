#include "Fraction.h"
#include <iostream>
#include <limits>
using std::cin;
using std::cout;
using std::runtime_error;

void RangeInput(int& n, const int& minN = std::numeric_limits<int>::min(), const int maxN = std::numeric_limits<int>::max())
{
    while (!(cin >> n) || n < minN || n > maxN)
    {
        cout << "Thu lai: ";
        cin.clear();
        cin.ignore(1000,'\n');
    }
}
int GCD(const int& a, const int& b)
{
    return (b == 0)? a : GCD(b, a % b);
}

Fraction::Fraction(): iTu(0), iMau(1){}

void Fraction::RutGon()
{
    if (iTu == 0)
    {
        iMau = 1;
        return;
    }

    int gcd = GCD(iTu, iMau);
    iTu /= gcd;
    iMau /= gcd;

    if (iMau < 0)
    {
        iTu *= -1;
        iMau *= -1;
    }
}

void Fraction::Nhap()
{
    cout << "Nhap tu: "; RangeInput(iTu);
    cout << "Nhap mau: "; do{RangeInput(iMau);} while (iMau == 0);
    RutGon();
}

void Fraction::Xuat() const
{
    if (iTu == 0) cout << "0";
    else if (iMau == 1) cout << iTu;
    else cout << iTu << "/" << iMau;
}

void Fraction::SoSanh(const Fraction& f1, const Fraction& f2)
{
    const int left = f1.iTu * f2.iMau, right = f2.iTu * f1.iMau;
    if (left > right) {
        f1.Xuat(); cout << " lon hon "; f2.Xuat();
    }
    else if (left < right) {
        f2.Xuat(); cout << " lon hon "; f1.Xuat();
    }
    else cout << "Hai phan so bang nhau";
    cout << ".\n";
}

Fraction Fraction::Tong(const Fraction& f1, const Fraction& f2)
{
    Fraction temp;
    temp.iTu = f1.iTu * f2.iMau + f2.iTu * f1.iMau;
    temp.iMau = f1.iMau * f2.iMau;
    temp.RutGon();
    return temp;
}

Fraction Fraction::Hieu(const Fraction& f1, const Fraction& f2)
{
    Fraction temp;
    temp.iTu = f1.iTu * f2.iMau - f2.iTu * f1.iMau;
    temp.iMau = f1.iMau * f2.iMau;
    temp.RutGon();
    return temp;
}

Fraction Fraction::Tich(const Fraction& f1, const Fraction& f2)
{
    Fraction temp;
    temp.iTu = f1.iTu * f2.iTu;
    temp.iMau = f1.iMau * f2.iMau;
    temp.RutGon();
    return temp;
}

Fraction Fraction::Thuong(const Fraction& f1, const Fraction& f2)
{
    if (f2.iTu == 0) throw runtime_error("PS 2 bang khong. Khong the chia cho 0.");
    Fraction temp;
    temp.iTu = f1.iTu * f2.iMau;
    temp.iMau = f1.iMau * f2.iTu;
    temp.RutGon();
    return temp;
}

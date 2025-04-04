#include "Complex.h"
#include <iostream>
#include <limits>
using std::cin;
using std::cout;
using std::runtime_error;

void RangeInput(double& n, const double& minN = -std::numeric_limits<double>::max(), const double maxN = std::numeric_limits<double>::max())
{
    while (!(cin >> n) || n < minN || n > maxN)
    {
        cout << "Thu lai: ";
        cin.clear();
        cin.ignore(1000,'\n');
    }
}

Complex::Complex() : iThuc(0), iAo(0){}
void Complex::Nhap()
{
    cout << "Nhap phan thuc: "; RangeInput(iThuc);
    cout << "Nhap phan ao: "; RangeInput(iAo);
}

Complex Complex::Tong(const Complex& n1, const Complex& n2)
{
    Complex temp;
    temp.iThuc = n1.iThuc + n2.iThuc;
    temp.iAo = n1.iAo + n2.iAo;
    return temp;
}
Complex Complex::Hieu(const Complex& n1, const Complex& n2)
{
    Complex temp;
    temp.iThuc = n1.iThuc - n2.iThuc;
    temp.iAo = n1.iAo - n2.iAo;
    return temp;
}

Complex Complex::Tich(const Complex& n1, const Complex& n2)
{
    Complex temp;
    temp.iThuc = n1.iThuc * n2.iThuc - n1.iAo * n2.iAo;
    temp.iAo = n1.iThuc * n2.iAo + n2.iThuc * n1.iAo;
    return temp;
}

Complex Complex::Thuong(const Complex& n1, const Complex& n2)
{
    Complex temp;
    double denominator = n2.iThuc * n2.iThuc + n2.iAo * n2.iAo;
    if (denominator == 0) throw runtime_error("Khong the chia cho 0");

    temp.iThuc = (n1.iThuc * n2.iThuc + n1.iAo * n2.iAo) / denominator;
    temp.iAo = (n1.iAo * n2.iThuc - n1.iThuc * n2.iAo) / denominator;
    return temp;
}

void Complex::Xuat() const
{
    // If has real
    if (iThuc != 0){
        cout << iThuc << " ";
        if (iAo > 0) cout << "+";
    }

    // If has imaginary
    if (iAo != 0){
        if (iAo != 1 && iAo != -1) cout << iAo;
        if (iAo == -1) cout << "-";
        cout << "i";
    }

    // If has none
    if (iAo == 0 && iThuc == 0) cout << 0;
}

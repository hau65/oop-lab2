#include "Time.h"
#include <iostream>
#include <limits>
using std::cout;
using std::cin;
void RangeInput(int& n, const int& minN = std::numeric_limits<int>::min(), const int maxN = std::numeric_limits<int>::max())
{
    while (!(cin >> n) || n < minN || n > maxN)
    {
        cout << "Thu lai: ";
        cin.clear();
        cin.ignore(1000,'\n');
    }
}

Time::Time() : iGio(0), iPhut(0), iGiay(0){}
void Time::Nhap()
{
    cout << "Nhap gio: "; RangeInput(iGio, 0, 23);
    cout << "Nhap phut: "; RangeInput(iPhut, 0, 59);
    cout << "Nhap giay: "; RangeInput(iGiay, 0, 59);
}

void Time::Xuat() const
{
    cout << iGiay << ":" << iPhut << ":" << iGio;
}

Time Time::TinhCongThemMotGiay()
{
    Time t = *this;
    t.iGiay++;
    if (t.iGiay == 60){
        t.iGiay = 0;
        t.iPhut++;
    }
    if (t.iPhut == 60){
        t.iPhut = 0;
        t.iGio++;
    }
    if (t.iGio == 24){
        t.iGio = 0;
    }
    return t;
}

#include <iostream>
#include <limits>
#include "NgayThangNam.h"
using namespace std;

// Helper functions
const int daysInMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
bool isLeapYear(const int& year) {
    return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
}
int getDaysInMonth(const int& month, const int& year){
    return (isLeapYear(year) && month == 2)? 29 : daysInMonth[month-1];
}

void RangeInput(int& n, const int& minN = numeric_limits<int>::min(), const int maxN = numeric_limits<int>::max())
{
    while (!(cin >> n) || n < minN || n > maxN)
    {
        cout << "Thu lai: ";
        cin.clear();
        cin.ignore(1000,'\n');
    }
}

//NgayThangNam functions
void NgayThangNam::Nhap()
{
    cout << "Nhap nam: ";
    RangeInput(iNam, 1);
    cout << "Nhap thang: ";
    RangeInput(iThang, 1, 12);
    cout << "Nhap ngay: ";
    RangeInput(iNgay, 1, getDaysInMonth(iThang, iNam));
}
void NgayThangNam::Xuat(){
    cout << iNgay << "/" << iThang << "/" << iNam;
}
void NgayThangNam::NgayThangNamTiepTheo()
{
    NgayThangNam temp = *this;
    temp.iNgay++;
    if (temp.iNgay > getDaysInMonth(iThang,iNam))
    {
        temp.iNgay = 1;
        temp.iThang++;
        if (temp.iThang > 12)
        {
            temp.iThang = 1;
            temp.iNam++;
        }
    }
    temp.Xuat();
}

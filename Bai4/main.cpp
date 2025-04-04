#include "Time.h"
#include <iostream>
using std::cout;

int main()
{
    Time t;
    t.Nhap();
    cout << "Thoi gian: "; t.Xuat();
    cout << "\nThem 1 giay: "; t.TinhCongThemMotGiay().Xuat();
    return 0;
}

#ifndef TIME_H
#define TIME_H


class Time
{
private:
    int iGio, iPhut, iGiay;
public:
    Time();
    void Nhap();
    void Xuat() const;
    Time TinhCongThemMotGiay();
};

#endif // TIME_H

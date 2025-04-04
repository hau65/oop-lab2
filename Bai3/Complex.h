#ifndef Complex_H
#define Complex_H

class Complex
{
private:
    double iThuc, iAo;
public:
    Complex();
    void Nhap();
    void Xuat() const;
    static Complex Tong(const Complex&, const Complex&);
    static Complex Hieu(const Complex&, const Complex&);
    static Complex Tich(const Complex&, const Complex&);
    static Complex Thuong(const Complex&, const Complex&);
};

#endif // Complex_H

#ifndef FRACTION_H
#define FRACTION_H


class Fraction
{
private:
    int iTu, iMau;

public:
    Fraction();
    void Nhap();
    void Xuat() const;
    void RutGon();

    static void SoSanh(const Fraction&, const Fraction&);
    static Fraction Tong(const Fraction&, const Fraction&);
    static Fraction Hieu(const Fraction&, const Fraction&);
    static Fraction Tich(const Fraction&, const Fraction&);
    static Fraction Thuong(const Fraction&, const Fraction&);
};

#endif // FRACTION_H

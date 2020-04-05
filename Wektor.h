#ifndef UNTITLED_WEKTOR_H
#define UNTITLED_WEKTOR_H

#include <iostream>

#define ROZMIAR 3

class Wektor {

    double tab[ROZMIAR];

public:
    Wektor();
    Wektor(double x, double y, double z);
    Wektor(double * tab);

    const Wektor  operator + (const Wektor & W2) const;
    const Wektor  operator - (const Wektor & W2) const;
    double operator * (const Wektor & W2) const; // SKALARNY

    const Wektor  operator * (double li) const;
    const Wektor  operator / (double li) const;

    bool operator == (const Wektor & W2) const;
    bool operator != (const Wektor & W2) const;

    double dlugosc() const;

    const double & operator[] (int index) const;
    double & operator[] (int index);


};

std::ostream & operator <<(std::ostream & strm, const Wektor & W);
std::istream & operator >>(std::istream & strm, Wektor & W);

Wektor operator * (double l1, Wektor W2);

#endif

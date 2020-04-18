#ifndef UNTITLED_WEKTOR_H
#define UNTITLED_WEKTOR_H

#include <iostream>

#define ROZMIAR 3
#define EPSILON 0.000000000000000000001

class Wektor {

    double tab[ROZMIAR];

public:
    Wektor();
    Wektor(double x, double y, double z);
    Wektor(double * tab);

    Wektor  operator + (const Wektor & W2) const;
    Wektor  operator - (const Wektor & W2) const;
    double operator * (const Wektor & W2) const; // SKALARNY

    Wektor  operator * (double li) const;
    Wektor  operator / (double li) const;

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

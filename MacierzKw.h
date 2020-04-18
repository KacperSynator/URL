#ifndef URL_MACIERZKW_H
#define URL_MACIERZKW_H

#include "Wektor.h"

/*****************************
***INTERPRETACJA WIERSZOWA****
******************************/

class MacierzKw {

    Wektor tabM[ROZMIAR];

    double Wyznacznik2x2(int wiersz,int kolumna); // wiersz/kolumna wykreślona

public:
    enum MetodaWyznacznik{Sarrus, Laplace, Gauss};

    MacierzKw();
    MacierzKw(Wektor *w);
    MacierzKw(double x1,double y1,double z1,double x2,double y2,double z2,double x3,double y3,double z3);
    MacierzKw(Wektor a1, Wektor a2, Wektor a3);

    const MacierzKw  transpozycja() const;

    Wektor operator * (const Wektor & W) const;
    MacierzKw operator * (MacierzKw & W) const;
    MacierzKw operator + (const MacierzKw & W) const;
    MacierzKw operator - (const MacierzKw & W) const;
    MacierzKw operator * (double l) const;
    MacierzKw operator / (double l) const;

    double Wyznacznik(MetodaWyznacznik Metoda);
    const MacierzKw  Odwrotnosc(); // z macierzy dopełnien

    bool operator == (const MacierzKw & W2) const;
    bool operator != (const MacierzKw & W2) const;

    const Wektor  ZwrocKolumne(int index);
    void ZmienKolumne(int index, Wektor nowa);

    const Wektor & operator[] (int index) const;
    Wektor & operator[] (int index);
};

const MacierzKw operator * (double l1,const MacierzKw W2);

std::ostream & operator << (std::ostream & strm,const MacierzKw & MK);
std::istream & operator >> (std::istream & strm, MacierzKw & MK);


#endif

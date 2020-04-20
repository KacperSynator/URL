#include <cmath>
#include "Wektor.h"
Wektor::Wektor()
{
    for(int i=0;i<ROZMIAR;i++)
        tab[i]=0;
}
Wektor::Wektor(double x, double y, double z)
{
    tab[0]=x;
    tab[1]=y;
    tab[2]=z;
}
Wektor::Wektor(double * tab1)
{
    for(int i=0;i<ROZMIAR;i++)
      tab[i]=tab1[i];
}
Wektor  Wektor:: operator + (const Wektor & W2) const
{
    Wektor WP;
    for(int i=0;i<ROZMIAR;i++)
        WP[i]=this->tab[i]+W2.tab[i];

    return WP;
}

 Wektor Wektor:: operator - (const Wektor & W2) const
{
    Wektor WP;
    for(int i=0;i<ROZMIAR;i++)
        WP[i]=this->tab[i]-W2.tab[i];

    return WP;
}
double Wektor:: operator * (const Wektor & W2) const// SKALARNY
{
    return this->tab[0]*W2.tab[0]+this->tab[1]*W2.tab[1]+this->tab[2]*W2.tab[2];
}
Wektor  Wektor:: operator * (double li) const
{
    Wektor WP;
    for(int i=0;i<ROZMIAR;i++)
        WP[i]=this->tab[i]*li;

    return WP;
}
Wektor Wektor:: operator / (double li) const
{
    if(li==0)
    {
     std::cout<<"Dzielenie przez zero"<<std::endl;
     exit(1);
    }
    Wektor WP;
    for(int i=0;i<ROZMIAR;i++)
        WP[i]=this->tab[i]/li;

    return WP;
}
Wektor operator * (double l1, Wektor W2)
{
    Wektor WP;
    for(int i=0;i<ROZMIAR;i++)
        WP[i]=l1*W2[i];

    return WP;
}

double Wektor:: dlugosc() const
{
    double wynik;
    wynik=tab[0]*tab[0]+tab[1]*tab[1]+tab[2]*tab[2];
    return sqrt(wynik);
}
const double & Wektor::  operator[] (int index) const {
    if (index < 0 || index >= ROZMIAR) {
        std::cerr << "poza zakresem" << std::endl;
        exit(1);
    }
    return tab[index];
}

double & Wektor::  operator[] (int index)
{
    if (index < 0 || index >= ROZMIAR) {
        std::cerr << "poza zakresem" << std::endl;
        exit(1);
    }
    return tab[index];
}
bool Wektor:: operator == (const Wektor & W2) const
{
    for(int i=0;i<ROZMIAR;i++)
        if(abs((*this)[i]-W2[i]) < EPSILON)
            return false;

    return true;
}
bool Wektor:: operator != (const Wektor & W2) const
{
    return !((*this)==W2);
}
std::ostream & operator <<(std::ostream & strm, const Wektor & W)
{
    strm<<'(';
    int i;
    for (i = 0; i < ROZMIAR-1; ++i)
        strm<<W[i]<<',';

    strm<<W[i]<<')';
    return strm;
}
std::istream & operator >>(std::istream & strm, Wektor & W)
{
    for(int i=0;i<ROZMIAR;i++)
         strm>>W[i];

    return strm;
}

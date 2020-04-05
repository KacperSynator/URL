#include <cmath>
#include "Wektor.h"
Wektor::Wektor()
{
    tab[0]=tab[1]=tab[2]=0;
}
Wektor::Wektor(double x, double y, double z)
{
    tab[0]=x;
    tab[1]=y;
    tab[2]=z;
}
Wektor::Wektor(double * tab1)
{
    tab[0]=tab1[0];
    tab[1]=tab1[1];
    tab[2]=tab1[2];
}
const Wektor  Wektor:: operator + (const Wektor & W2) const
{
    double x,y,z;
    x=this->tab[0]+W2.tab[0];
    y=this->tab[1]+W2.tab[1];
    z=this->tab[2]+W2.tab[2];
    return Wektor(x,y,z);
}

const Wektor Wektor:: operator - (const Wektor & W2) const
{
    double x,y,z;
    x=this->tab[0]-W2.tab[0];
    y=this->tab[1]-W2.tab[1];
    z=this->tab[2]-W2.tab[2];
    return Wektor(x,y,z);
}
double Wektor:: operator * (const Wektor & W2) const// SKALARNY
{
    return this->tab[0]*W2.tab[0]+this->tab[1]*W2.tab[1]+this->tab[2]*W2.tab[2];
}
const Wektor  Wektor:: operator * (double li) const
{
    double x,y,z;
    x=this->tab[0]*li;
    y=this->tab[1]*li;
    z=this->tab[2]*li;
    return Wektor(x,y,z);
}
const Wektor Wektor:: operator / (double li) const
{
    if(li==0)
    {
     std::cout<<"Dzielenie przez zero"<<std::endl;
     exit(1);
    }
    double x,y,z;
    x=this->tab[0]/li;
    y=this->tab[1]/li;
    z=this->tab[2]/li;
    return Wektor(x,y,z);
}
Wektor operator * (double l1, Wektor W2)
{
    double x,y,z;
    x=W2[0]*l1;
    y=W2[1]*l1;
    z=W2[2]*l1;
    return Wektor(x,y,z);
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
        if((*this)[i]!=W2[i])
            return false;

    return true;
}
bool Wektor:: operator != (const Wektor & W2) const
{
    return !((*this)==W2);
}
std::ostream & operator <<(std::ostream & strm, const Wektor & W)
{
    strm<<'('<< W[0] <<','<< W[1] <<','<< W[2] <<')';
    return strm;
}
std::istream & operator >>(std::istream & strm, Wektor & W)
{
  strm>>W[0]>>W[1]>>W[2];
    return strm;
}

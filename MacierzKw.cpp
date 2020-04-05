#include "MacierzKw.h"

MacierzKw::MacierzKw()
{
    for(int i=0;i<ROZMIAR;i++)
        for(int j=0;j<ROZMIAR;j++)
            tabM[i][j]=0;
}
MacierzKw::MacierzKw(Wektor *w)
{
    for(int i=0;i<ROZMIAR;i++)
            tabM[i]=w[i];
}
MacierzKw::MacierzKw(double x1,double y1,double z1,double x2,double y2,double z2,double x3,double y3,double z3)
{
    tabM[0][0]=x1;
    tabM[0][1]=y1;
    tabM[0][2]=z1;
    tabM[1][0]=x2;
    tabM[1][1]=y2;
    tabM[1][2]=z2;
    tabM[2][0]=x3;
    tabM[2][1]=y3;
    tabM[2][2]=z3;

}
MacierzKw::MacierzKw(Wektor a1, Wektor a2, Wektor a3)
{
    tabM[0]=a1;
    tabM[1]=a2;
    tabM[2]=a3;
}

const MacierzKw  MacierzKw:: transpozycja() const
{
    MacierzKw MKP;
    for(int i=0;i<ROZMIAR;i++)
        for (int j = 0; j < ROZMIAR; j++)
            MKP[j][i]=(*this)[i][j];

    return MKP;
}

const Wektor MacierzKw:: operator * (const Wektor & W) const
{
    Wektor WP;
    for(int i=0;i<ROZMIAR;i++)
        WP[i]=(*this)[i]*W;

    return WP;
}

const MacierzKw MacierzKw:: operator * (MacierzKw & W) const
{
    MacierzKw MKP;
    for(int i=0;i<ROZMIAR;i++)
        for(int j=0;j<ROZMIAR;j++)
            MKP[i][j]=(*this)[i]*W.ZwrocKolumne(j);

    return MKP;
}

const MacierzKw MacierzKw:: operator + (const MacierzKw & W) const
{
    MacierzKw MKP;
    for(int i=0;i<ROZMIAR;i++)
        MKP[i]=(*this)[i]+W[i];

    return MKP;
}

const MacierzKw MacierzKw:: operator - (const MacierzKw & W) const
{
    MacierzKw MKP;
    for(int i=0;i<ROZMIAR;i++)
        MKP[i]=(*this)[i]-W[i];

    return MKP;
}
const MacierzKw MacierzKw:: operator / (double l) const
{
    if(l==0)
    {
        std::cout<<"Dzielenie przez zero"<<std::endl;
        exit(1);
    }
    MacierzKw MKP;
    for(int i=0;i<ROZMIAR;i++)
        MKP[i]=(*this)[i]/l;

    return MKP;
}

const MacierzKw MacierzKw:: operator * (double l) const
{
    MacierzKw MKP;
    for(int i=0;i<ROZMIAR;i++)
       MKP[i]=(*this)[i]*l;

    return MKP;
}
const MacierzKw operator * (double l1,const MacierzKw W2) {
    MacierzKw MKP;
    for (int i = 0; i < ROZMIAR; i++)
        MKP[i] = W2[i] * l1;

    return MKP;
}
double MacierzKw:: Wyznacznik2x2(int wiersz,int kolumna) // wiersz/kolumna wykreślona
{
    double M2x2[4];
    int k = 0;
    for (int i = 0; i < ROZMIAR; i++)
    {
        if (i == wiersz && i != ROZMIAR - 1) i++;
        for (int j = 0; j < ROZMIAR; j++)
            if (i != wiersz && j != kolumna)
            {
                M2x2[k] = tabM[i][j];
                k++;
            }
    }
    return M2x2[0]*M2x2[3]-M2x2[1]*M2x2[2];
}
double MacierzKw:: WyznacznikL() // względem pierwszego wiersza
{
     double wynik=0;
     for(int i=0;i<ROZMIAR;i++)
     {
        if(i%2==1)
         wynik-= tabM[0][i] * Wyznacznik2x2(0,i);
        else
         wynik+= tabM[0][i] * Wyznacznik2x2(0,i);
     }
    return wynik;
}

const MacierzKw  MacierzKw:: Odwrotnosc()
{
    MacierzKw MKP;
    double wyznacznik=WyznacznikL();
    if(wyznacznik==0)
    {
        std::cout<<"Macierz nie jest odwracalna"<<std::endl;
        exit(1);
    }
    for(int i=0;i<ROZMIAR;i++)
        for(int j=0;j<ROZMIAR;j++)
        {
            if((i+j)%2==0)
                MKP[i][j]=Wyznacznik2x2(i,j);
            else
                MKP[i][j]=-Wyznacznik2x2(i,j);
        }
    MKP=MKP.transpozycja();
    return MKP/wyznacznik;
}

const Wektor  MacierzKw:: ZwrocKolumne(int index)
{
    if (index < 0 || index >= ROZMIAR) {
        std::cerr << "poza zakresem" << std::endl;
        exit(1);
    }
    Wektor WP;
    for(int i=0;i<ROZMIAR;i++)
        WP[i]=tabM[i][index];

    return WP;
}

void MacierzKw:: ZmienKolumne(int index, Wektor nowa)
{
    if (index < 0 || index >= ROZMIAR) {
        std::cerr << "poza zakresem" << std::endl;
        exit(1);
    }
    for(int i=0;i<ROZMIAR;i++)
        tabM[i][index]=nowa[i];

}

bool MacierzKw:: operator == (const MacierzKw & W2) const
{
    for(int i=0;i<ROZMIAR;i++)
        if((*this)[i]!=W2[i])
            return false;

    return true;
}

bool MacierzKw:: operator != (const MacierzKw & W2) const
{
    return !(W2==(*this));
}

const Wektor & MacierzKw:: operator[] (int index) const
{
    if (index < 0 || index >= ROZMIAR) {
        std::cerr << "poza zakresem" << std::endl;
        exit(1);
    }
    return tabM[index];
}

Wektor & MacierzKw:: operator[] (int index)
{
    if (index < 0 || index >= ROZMIAR) {
        std::cerr << "poza zakresem" << std::endl;
        exit(1);
    }
    return tabM[index];
}

std::ostream & operator << (std::ostream & strm,const MacierzKw & MK)
{
    strm<< MK[0] << std::endl << MK[1] << std:: endl << MK[2] ;
    return strm;
}
std::istream & operator >> (std::istream & strm, MacierzKw & MK)
{
    strm>> MK[0] >> MK[1] >> MK[2];
    return strm;
}
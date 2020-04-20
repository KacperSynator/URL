#include "UkladRownan.h"
#include <iomanip>

void UkladRownan:: ZmienWektorWolny(Wektor nowy)
{
    B=nowy;
}

void UkladRownan:: ZmienMacierz(MacierzKw nowy)
{
    A=nowy;
}


Wektor UkladRownan:: Oblicz(const MetodaOliczania Metoda)
{
    Wektor X;
    MacierzKw MP;
    switch (Metoda)
    {
        case MacierOdwrotna:
            X=A.Odwrotnosc()*B;
            break;

        case Cramer:
            {
            double wyzG = A.Wyznacznik(MacierzKw::Laplace);
            if (wyzG == 0) {
                std::cout << "Równanie sprzeczne lub jest nieskończenie wiele rozwiązań" << std::endl;
                exit(1);
            }
            for (int i = 1; i <= ROZMIAR; ++i) {
                MP = A;
                MP.ZmienKolumne(i - 1, B);
                X[i - 1] = MP.Wyznacznik(MacierzKw::Laplace) / wyzG;
            }
            break;
        }

        case Gauss:
            MP=A;
            X=B;
            double l;
            if(A.Wyznacznik(MacierzKw::Gauss)==0) {
                std::cout << "Równanie sprzeczne lub jest nieskończenie wiele rozwiązań" << std::endl;
                exit (1);
            }
            else
            for (int i = 0; i <ROZMIAR-1 ; ++i)
            {
                if(MP[i][i]==0)
                {
                    for (int k = 0; k < ROZMIAR; k++)
                    {
                        if (MP[i][k] != 0)
                        {
                            Wektor WP = MP[i];
                            double lp=X[i];
                            MP[i] = MP[k];
                            X[i]=X[k];
                            MP[k] = WP;
                            X[k]=lp;
                            break;
                        }
                    }

                }
                for (int j = i+1; j <ROZMIAR ; ++j)
                {
                    if(MP[i][i]!=0)
                        l = MP[j][i]/MP[i][i];
                    else
                    {}
                    MP[j]=MP[j]-l*MP[i];
                    X[j]=X[j]-l*X[i];
                }
            }
            for (int i = ROZMIAR-1; i >0 ; --i)
            {
                if(MP[i][i]==0)
                {
                    for (int k = 0; k < ROZMIAR; k++)
                    {
                        if (MP[i][k] != 0)
                        {
                            Wektor WP = MP[i];
                            double lp=X[i];
                            MP[i] = MP[k];
                            X[i]=X[k];
                            MP[k] = WP;
                            X[k]=lp;
                            break;
                        }
                    }

                }
                for (int j =i-1; j >=0 ; --j)
                {
                    double l = MP[j][i]/MP[i][i];
                    MP[j]=MP[j]-l*MP[i];
                    X[j]=X[j]-l*X[i];
                }
            }
            for(int i=0;i<ROZMIAR;i++)
            {
                X[i]=X[i]/MP[i][i];
            }
            break;

    }
    return X;
}

std::ostream & operator << (std::ostream & strm, UkladRownan  & UR)
{
    for (int i = 0; i < ROZMIAR; ++i)
    {
        strm<<'|';
        for (int j = 0; j < ROZMIAR; ++j)
            strm << std::setw(7) << UR.ZwrocMcierz()[i][j];

        strm<< std::setw(2)<<'|'<<std::setw(2)<<"| x_"<<i+1<<" |";
        if(i+1==(ROZMIAR+1)/2)
            strm<<std::setw(3)<<'='<<std::setw(3)<<'|'<<std::setw(7)<<UR.ZwrocWektorWolny()[i]<<std::setw(2)<<'|'<<std::endl;
        else
            strm<<std::setw(6)<<'|'<<std::setw(7)<<UR.ZwrocWektorWolny()[i]<<std::setw(2)<<'|'<<std::endl;
    }

    return strm;
}

std::istream & operator >> (std::istream & strm, UkladRownan & UR)
{
    MacierzKw MP;
    Wektor WP;

    strm>>MP>>WP;
    UR.ZmienMacierz(MP.transpozycja());
    UR.ZmienWektorWolny(WP);

    return  strm;
}
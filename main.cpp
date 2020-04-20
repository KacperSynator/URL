#include <iostream>
#include "Wektor.h"
#include "UkladRownan.h"

int main() {
    std::cout<<"Program oblicza uklad rownan liniowych"<<std::endl;
    std::cout<<"Wprowadź dane:"<<std::endl;
    UkladRownan UR;
    std::cin>>UR;

    /*MacierzKw MK;
    std::cin>>MK;
    std::cout<<MK.Wyznacznik(MacierzKw::Sarrus)<<' '<<MK.Wyznacznik(MacierzKw::Laplace)<<' '<<MK.Wyznacznik(MacierzKw::Gauss)<<std::endl;
*/
    if(!(std::cin.good()))
    {
        std::cout<< "Zly format, sprobuj ponownie"<<std::endl;
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        std::cin>>UR;
    }

    std::cout<<"Podany uklad rownan liniowych:"<<std::endl;
    std::cout<<UR<<std::endl;

    std::cout<<std::endl;

    Wektor X1=UR.Oblicz(UkladRownan::Cramer);
    Wektor E1=UR.ZwrocMcierz()*X1-UR.ZwrocWektorWolny();
    Wektor X2=UR.Oblicz(UkladRownan::MacierOdwrotna);
    Wektor E2=UR.ZwrocMcierz()*X2-UR.ZwrocWektorWolny();
    Wektor X3=UR.Oblicz(UkladRownan::Gauss);
    Wektor E3=UR.ZwrocMcierz()*X1-UR.ZwrocWektorWolny();
    if(E1.dlugosc()==E2.dlugosc() && E1.dlugosc()==E3.dlugosc())
        std::cout<<"Wszystkie sposoby są równie dokładne"<<std::endl<<"Obliczanie metoda: ";
    else
        std::cout<<"Najlepszym sposobem rozwiazania jest metoda: ";

    double najm=std::min(std::min(E1.dlugosc(),E2.dlugosc()),E3.dlugosc());

    if(najm==E1.dlugosc())
    {
        std::cout<<"Cramera"<<std::endl;
        std::cout<<"Wektor X= "<< X1 << std::endl;
        std::cout<<"Wektor bledu Ax-b=" << E1 << std::endl;
        std::cout<<"Dlugusc wektor bledu |Ax-b|= "<< E1.dlugosc()<< std::endl;
    }
    else if(najm==E2.dlugosc())
    {
        std::cout<<"MacierzyOdwrotnej"<<std::endl;
        std::cout<< "Wektor X= "<< X2 << std::endl;
        std::cout<<"Wektor bledu Ax-b=" << E2 << std::endl;
        std::cout<<"Dlugusc wektor bledu |Ax-b|= "<< E2.dlugosc()<< std::endl;
    }
    else if(najm==E3.dlugosc())
    {
        std::cout<<"Gaussa"<<std::endl;
        std::cout<<"Wektor X= "<< X3 << std::endl;
        std::cout<<"Wektor bledu Ax-b=" << E3 << std::endl;
        std::cout<<"Dlugusc wektor bledu |Ax-b|= "<< E3.dlugosc()<< std::endl;
    }


}

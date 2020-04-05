#include <iostream>
#include "Wektor.h"
#include "MacierzKw.h"

int main() {
    Wektor wektor1(5,4,-7);
    Wektor wektor2(1,3,-1);
    Wektor wektor3(2,0,-3);
    MacierzKw MK(wektor1,wektor2,wektor3);
    if(!(std::cin.good()))
    {
        std::cout<< "Zly format wektora"<<std::endl;
        std::cin.clear();
        std::cin.ignore(10000,'\n');
    }
    std::cout<< MK << std::endl<<std::endl;
    std::cout<< MK.Odwrotnosc()<< std::endl<<std::endl;
}

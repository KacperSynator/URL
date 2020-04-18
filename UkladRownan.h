#ifndef URL_UKLADROWNAN_H
#define URL_UKLADROWNAN_H

#include "MacierzKw.h"

class UkladRownan {

MacierzKw A;
Wektor B;

public:

    enum MetodaOliczania{MacierOdwrotna, Cramer, Gauss};

    UkladRownan() = default;
    UkladRownan(MacierzKw AA, Wektor bb) : A(AA), B(bb) {};

    const Wektor & ZwrocWektorWolny() { return B; };
    const MacierzKw & ZwrocMcierz() { return A; };

    void ZmienWektorWolny(Wektor nowy);
    void ZmienMacierz(MacierzKw nowy);

    Wektor Oblicz(MetodaOliczania Metoda);

};

std::ostream & operator << (std::ostream & strm, UkladRownan & UR);
std::istream & operator >> (std::istream & strm, UkladRownan & UR);

#endif

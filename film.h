#include <iostream>
#include <string>

#ifndef FILM_H
#define FILM_H

#include "string.h"

///getline
namespace cp {
    String& getline(std::istream& is, String& str) {
        str = "";
        char c;
        while (is.get(c)) {
            if (c == '\n') {
                break;
            }
            if (c == '\r') {
                continue;
            }
        str = str + c;
        }
        return str;
    }
}

class Film {
protected:
    String cim;
    int hossz;
    int kiadasEv;

public:
    /// konstruktorok
    Film() { cim = ""; hossz = 0; kiadasEv = 0; }
    Film(String c, int h = 0, int k = 0) : cim(c), hossz(h), kiadasEv(k){}

    /// destruktor
    virtual ~Film() { cim = ""; hossz = 0; kiadasEv = 0; }

    /// qetterek
    String getCim()const {return cim;}
    int getHossz()const {return hossz;}
    int getKiadasEv()const {return kiadasEv;}

    /// copy ctr
    Film(const Film& rhs){
            cim = rhs.cim;
            hossz = rhs.hossz;
            kiadasEv = rhs.kiadasEv;

    }
    /// assign operator
    Film& operator=(const Film& rhs){
        if(this != &rhs){
            cim = rhs.cim;
            hossz = rhs.hossz;
            kiadasEv = rhs.kiadasEv;
        }
        return *this;
    }

    /// kiirja a standard outputra
    virtual void kiir() const {
        if(cim == "") throw "Nincs mit kiirni"; //cim nelkuli film nem lehet
        std::cout << "\nCim: \t\t\t" << cim << std::endl << "Hossz: \t\t\t" << hossz << std::endl << "Kiadas eve: \t\t" << kiadasEv << std::endl;
    }

    /// standard inputrol beolvas
     Film* beolvas() {
        String c = "";
        int h;
        int e;

        std::cout << "Cim: ";
        std::cin.ignore();
        cp::getline(std::cin, c);


        std::cout << "Hossz: ";
        std::cin >> h;

        std::cout << "Kiadas eve: ";
        std::cin >> e;

        if(c == "" || h <= 0 ) throw "Ilyen film nem letezhet, negativ hossz vagy cim nelkuli";
        return new Film(c,h,e);
    }
};

//Fajlba irashoz kell
std::ostream& operator<<(std::ostream& os, const Film& film) {
    os << film.getCim() << " (" << film.getHossz() << " perc, " << film.getKiadasEv() << ")";
    return os;
}
#endif // FILM_H


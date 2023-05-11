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
    ///Parameter nelkuli ctr
    Film() { cim = ""; hossz = 0; kiadasEv = 0; }

    Film(String c, int h = 0, int k = 0) : cim(c), hossz(h), kiadasEv(k){}

    // Destruktor
    virtual ~Film() { cim = ""; hossz = 0; kiadasEv = 0; }

    ///Copy ctr
    Film(const Film& rhs){
            cim = rhs.cim;
            hossz = rhs.hossz;
            kiadasEv = rhs.kiadasEv;

    }
    ///Assign operator
    Film& operator=(const Film& rhs){
        if(this != &rhs){
            cim = rhs.cim;
            hossz = rhs.hossz;
            kiadasEv = rhs.kiadasEv;
        }
        return *this;
    }



    ///Getterek
    String getCim(){return cim;}
    int getHossz(){return hossz;}
    int getKiadasEv(){return kiadasEv;}

    ///Kiirja a standard outputra
    virtual void kiir() const {
        std::cout << "\nCim: \t\t\t" << cim << std::endl << "Hossz: \t\t\t" << hossz << std::endl << "Kiadas eve: \t\t" << kiadasEv << std::endl;
    }

    ///Standard inputrol beolvas
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
        return new Film(c,h,e);
    }

};





#endif // FILM_H


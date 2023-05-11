#include <iostream>
#include <string>

#ifndef CSALADIFILM_H
#define CSALADIFILM_H

#include "string.h"
class CsaladiFilm : public Film {
    int korhatar;

public:
    ///ctr-ek
    CsaladiFilm(): Film(), korhatar(0){}
    CsaladiFilm(String c, int h, int k, int korh) : Film(c, h, k), korhatar(korh) {}
    ~CsaladiFilm() { korhatar = 0; }

    ///cpy ctr
    CsaladiFilm(const CsaladiFilm& rhs) : Film(rhs){
        korhatar = rhs.korhatar;
    }

    ///assign operator
    CsaladiFilm& operator=(const CsaladiFilm& rhs){
        if(this != &rhs){
            Film::operator=(rhs);
            korhatar = rhs.korhatar;
        }
        return *this;
    }

    ///getter
    int getKorhatar(){return korhatar;}


    ///kiiras visszavezetve a Film osztalyra, utana irja ki az extra adattagot
    virtual void kiir() const override {
        Film::kiir();
        std::cout << "Korhatar: \t\t" << korhatar << std::endl;
    }

    ///beolvasas szinten visszavezetve a Film-re
     CsaladiFilm* beolvasCsaladi() {
        Film* temp = Film::beolvas();
        int kh;
        std::cout << "Korhatar: ";
        std::cin>> kh;

        CsaladiFilm* uj = new CsaladiFilm(temp->getCim(), temp->getHossz(), temp->getKiadasEv(), kh);
        delete temp;                  //a Film mar nem kell, bemasoltuk a Csaladiba, torolni kell
        return uj;
    }

};


#endif // CSALADIFILM_H

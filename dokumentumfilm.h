#include <iostream>
#include <string>

#ifndef DOKUMENTUMFILM_H
#define DOKUMENTUMFILM_H

#include "string.h"

class DokumentumFilm : public Film {
    String leiras;

public:
    ///ctr-ek
    DokumentumFilm() : Film(), leiras("") {}
    DokumentumFilm(String c, int h, int k, String l) : Film(c, h, k), leiras(l) {}
    ~DokumentumFilm() { leiras = ""; }

    ///copy ctr
    DokumentumFilm(const DokumentumFilm& rhs) : Film(rhs){
        leiras = rhs.leiras;
    }

    ///assign operator
    DokumentumFilm& operator=(const DokumentumFilm& rhs){
        if(this != &rhs){
            Film::operator=(rhs);
            leiras = rhs.leiras;
        }
        return *this;
    }
    ///getter
    String getLeiras()const {return leiras;}

    ///kiiras visszavezetve a Film-re
    virtual void kiir() const override {
        Film::kiir();
        std::cout << "Leiras: \t\t" << leiras << std::endl;
    }

    ///beolvasas ismet a Film-et felhasznalva
     DokumentumFilm* beolvasDokumentum() {
        Film* temp = Film::beolvas();
        String l;
        std::cout << "Leiras: ";
        std::cin.ignore();
        cp::getline(std::cin, l);

        DokumentumFilm* uj = new DokumentumFilm(temp->getCim(), temp->getHossz(), temp->getKiadasEv(), l);
        delete temp;              //a Film mar nem kell, bemasoltuk a Dokumentumba, torolni kell
        return uj;
    }

};
#endif // DOKUMENTUMFILM_H

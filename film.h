#include <iostream>
#include <string>

#ifndef FILM_H
#define FILM_H

#include "string.h"
#include "string.hpp"
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

class CsaladiFilm : public Film {
    int korhatar;

public:
    ///ctr-ek
    CsaladiFilm(): Film(), korhatar(0){}
    CsaladiFilm(String c, int h, int k, int korh) : Film(c, h, k), korhatar(korh) {}
    virtual ~CsaladiFilm() { korhatar = 0; }

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
        delete[] temp;                  //a Film mar nem kell, bemasoltuk a Csaladiba, torolni kell
        return uj;
    }

};

class DokumentumFilm : public Film {
    String leiras;

public:
    ///ctr-ek
    DokumentumFilm() : Film(), leiras("") {}
    DokumentumFilm(String c, int h, int k, String l) : Film(c, h, k), leiras(l) {}
    virtual ~DokumentumFilm() { leiras = ""; }

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
    String getLeiras(){return leiras;}

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
        delete[] temp;              //a Film mar nem kell, bemasoltuk a Dokumentumba, torolni kell
        return uj;
    }

};




#endif // FILM_H


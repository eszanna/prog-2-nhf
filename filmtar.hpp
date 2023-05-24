#ifndef FILMTAR_HPP
#define FILMTAR_HPP

#include <string>
#include <iostream>

#include "memtrace.h"
#include "film.h"
#include "dokumentumfilm.h"
#include "csaladifilm.h"

/// tobbfele filmet tarolni tudo filmtar osztaly alias heterogen kollekcio

class Filmtar : public Film {
    static const size_t kezdo_kapacitas = 10;
    Film** tar;
    size_t kapacitas;
    size_t db;

public:
    /// konstruktor default ertekekkel a memszivargas elkerulese erdekeben 0-val es nullptr-rel kezdve
    Filmtar() : tar(new Film*[kezdo_kapacitas]()), kapacitas(kezdo_kapacitas), db(0) { }

    /// destruktor
    ~Filmtar() {
         for (size_t i = 0; i < db+1; i++) {
            delete tar[i];
        }
        delete[] tar;
    }

    /// visszadja, hogy hany film van a tarban
    size_t size() const { return db; }

    /// parameterkent kapott filmet tesz a tarba
    void felvesz(Film* ap){
        if (db >= kapacitas) {
            //ha tele az eddigi, ujat foglalunk, 10-zel nagyobbat
            kapacitas += 10;
            Film** uj_tar = new Film* [kapacitas]();
            for (size_t i = 0; i < db; i++) {         //belemasoljuk a regit
                uj_tar[i] = tar[i];
                delete tar[i];
            }

            delete[] tar;
            tar = uj_tar;
            for (size_t i = 0; i < db; ++i)
                delete uj_tar[i];
        }
            tar[db++] = ap; //mindenkeppen hozzaadjuk a vegere
    }

    /// kiirja az osszes filmet
    void kiir() const {
        if(size() == 0) throw "Nincs mit kiirni";
        for (size_t i = 0; i < db; i++)
            tar[i]->kiir();
    }

    /// torli a parameterkent kapott filmet
    void torol(size_t idx){
        if(idx>db)
            throw "Index error";
        delete tar[idx];
        for (size_t i = idx; i < db-1; i++) {
            tar[i] = tar[i+1];
        }
        db--;
    }

    /// indexelo operator
    Film& operator[](size_t idx) const {
        if(idx < db)
            return *tar[idx];
        else
            throw "Index error";
    }

    /// fajlba irja a filmlistat
    void fajlba(const String& filename){
        std::ofstream file(filename.c_str());
        if(!file.is_open()){
            throw "Nem sikerult megnyitni a fajlt.\n";
            return;
        }
        for (size_t i = 0; i < db; i++) {
            file << *tar[i] << std::endl;
        }

        file.close();
    }

};

#endif // FILMTAR_HPP

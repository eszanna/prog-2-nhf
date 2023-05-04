#ifndef FILMTAR_HPP
#define FILMTAR_HPP


#include <string>
#include <iostream>


//#define MEMTRACE
//#define MEMTRACE_CPP
#include "memtrace.h"


#include "film.h"


///tobbfele filmet tarolni tudo filmtar osztaly
template<class T>

class Filmtar : public Film{
    static const size_t kezdo_kapacitas = 10;
    T* tar;
    size_t kapacitas;
    size_t db;

public:
    ///konstruktor default ertekekkel a memszivargas elkerulese erdekeben 0-val es nullptr-rel kezdve
    Filmtar() : tar(new T[kezdo_kapacitas]()), kapacitas(kezdo_kapacitas), db(0) { }

    ///visszadja, hogy hany film van a tarban
    size_t size() const { return db; }

    ///parameterkent kapott filmet tesz a tarba
    void felvesz(const T& ap){
        if(db >= kapacitas){
            //std::cout << "Ujat kellett foglalni mert tele lett" << std::endl; //ha tele az eddigi, ujat foglalunk, 10-zel nagyobbat
            kapacitas += 10;
            T* uj_tar = new T[kapacitas]();
            for(size_t i = 0; i<db; i++)          //belemasoljuk a regit
                uj_tar[i] = tar[i];

            delete[] tar;
            tar = uj_tar;
        }
        tar[db++] = ap;                             //mindenkeppen hozzaadjuk a vegere
    }

    ///kiirja az osszes filmet
    void kiir() const {
        for (size_t i = 0; i < db; i++)
            tar[i].kiir();
    }

    ///torli a parameterkent kapott filmet
    void torol(size_t idx){
        if(idx>db)
            throw "Index error";
        tar[idx] = T();
        for (size_t i = idx; i < db-1; i++) {
            tar[i] = tar[i+1];
            
        }
        db--;
    }

    ///destruktor
   // ~Filmtar(){
    // for(size_t i = 0; i < db; i++)
    //    torol(i);
    //}

    ~Filmtar() { delete[] tar; }

    ///indexelo operator
    Film operator[](size_t idx) {
        if(idx < db)
            return tar[idx];
        else
            throw "Index error";
    }
};

#endif // FILMTAR_HPP

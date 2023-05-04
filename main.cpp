#include <iostream>



#include "memtrace.h"

#include "film.h"
#include "filmtar.hpp"
#include "gtest_lite.h"

#define MEMTRACE_CPP


void leak(){int* ptr = new int;}

int main() {
    std::cout << "Udv a FILMTAR nagyhazimban!" << std::endl;
/*
    Filmtar<Film> filmtarolo;
    Filmtar<DokumentumFilm> doktarolo;
    Filmtar<CsaladiFilm> csaladitarolo;

//egy par film alapbol van benne, teszt

    Film e = Film("A kigyo labnyomai", 93, 1979);
    CsaladiFilm k = CsaladiFilm("Piroska es a farkalok", 90, 1995, 6);
    DokumentumFilm h = DokumentumFilm("A csigak szexualitasa", 3600, 2006, "Megismerhetjuk ezen csodalatos himnos allatok szaporodasat.");
    DokumentumFilm cs = DokumentumFilm("A csiga hazamegy", 1, 2003, "Hat most errol mit mondjak.");
    Film s = Film("Star Wars 19: A robotok nemi elete", 69, 2020);

    filmtarolo.felvesz(e);
    filmtarolo.felvesz(s);
    doktarolo.felvesz(h);
    doktarolo.felvesz(cs);
    csaladitarolo.felvesz(k);


    int menu;

    while(menu != 6){

        std::cout << "\nValassz a kovetkezo menupontok kozul:" << std::endl;
        std::cout << "\n\t1: Filmlista kiirasa" << std::endl;
        std::cout << "\t2: Kereses cim alapjan" << std::endl;
        std::cout << "\t3: Uj film hozzaadasa" << std::endl;
        std::cout << "\t4: Film torlese" << std::endl;
        std::cout << "\t5. Filmlista fajlba irasa" << std::endl;
        std::cout << "\t6: Kilepes" << std::endl;
        std::cout << "Valasztott menupont: ";
        std::cin >> menu;

        if (menu == 1) {
                filmtarolo.kiir();
                doktarolo.kiir();
                csaladitarolo.kiir();
        }

        else if(menu == 2){
                int tip;

                std::cout << "\nAdd meg a keresett film tipusat: 1 - Film, 2 - Csaladi film, 3 - Dokumentumfilm : ";
                std::cin >> tip;

                std::string c = "";
                std::cout << "\nAdd meg a keresett film cimet:  ";
                std::cin.ignore();
                cp::getline(std::cin, c);


        try{
            switch(tip) {
            case 1:
                for(size_t i = 0; i < filmtarolo.size(); i++) {
                    if(filmtarolo[i].getCim() == c) {
                        filmtarolo[i].kiir();
                    }else std::cout << "Nincs ilyen film";
                }
                break;
            case 2:
                for(size_t i = 0; i < csaladitarolo.size(); i++) {
                    if(csaladitarolo[i].getCim() == c) {
                        csaladitarolo[i].kiir();

                    }else std::cout << "Nincs ilyen film";
                }
                break;
            case 3:
                for(size_t i = 0; i < doktarolo.size(); i++) {
                    if(doktarolo[i].getCim() == c) {
                        doktarolo[i].kiir();

                    }else std::cout << "Nincs ilyen film";
                }
                break;

            default:
                throw "Nincs ilyen tipus!";
            }
        } catch (const char* msg){
            std::cout << "Hiba: " << msg << " Irj be megfelelo tipust 1-2-3" << std::endl;
            }
        }


        else if (menu == 3) {
                int tipus;
                std::cout<<"\nMilyen tipusu lesz a felvett film?  1 - Film, 2 - Csaladi film, 3 - Dokumentumfilm : ";
                std::cin >> tipus;

                if(tipus == 1){
                    Film ujf = ujf.beolvas();
                    filmtarolo.felvesz(ujf);
                    std::cout<<"\nA modositott filmlista: "<<std::endl;
                    filmtarolo.kiir();

                }

                else if(tipus == 2){
                    CsaladiFilm ujcs = ujcs.beolvasCsaladi();
                    csaladitarolo.felvesz(ujcs);
                    std::cout<<"\nA modositott csaladifilmlista: "<<std::endl;
                    csaladitarolo.kiir();

                }
                else if(tipus == 3){
                    DokumentumFilm ujd = ujd.beolvasDokumentum();
                    doktarolo.felvesz(ujd);
                    std::cout<<"\nA modositott doksifilmlista: "<<std::endl;
                    doktarolo.kiir();

                }
            else
                throw "Nincs ilyen tipus";

}

         else if(menu == 4){
                int tip;
                std::cout << "\nAdd meg a torolni kivant film tipusat:  1 - Film, 2 - Csaladi film, 3 - Dokumentumfilm :";
                std::cin >> tip;

                std::string c = "";
                std::cout << "\nAdd meg a torolni kivant film cimet:  ";
                std::cin.ignore();
                std::getline(std::cin, c);

        try{
            switch(tip){
                case 1:
                    for(size_t i = 0; i<filmtarolo.size(); i++){
                        if(filmtarolo[i].getCim() == c){
                            filmtarolo.torol(i);
                        }
                    }
                    std::cout<<"\nA modositott filmlista: "<<std::endl;
                    filmtarolo.kiir();
                    break;

               case 2:
                    for(size_t i = 0; i<csaladitarolo.size(); i++){
                        if(csaladitarolo[i].getCim() == c){
                            csaladitarolo.torol(i);
                        }
                    }
                    std::cout<<"\nA modositott csaladifilmlista: "<<std::endl;
                    csaladitarolo.kiir();
                    break;

                case 3:
                    for(size_t i = 0; i<doktarolo.size(); i++){
                        if(doktarolo[i].getCim() == c){
                            doktarolo.torol(i);
                        }
                    }
                    std::cout<<"\nA modositott dokumentumfilmlista:: "<<std::endl;
                    doktarolo.kiir();
                    break;

                default:
                    throw "Nincs ilyen tipus";

            }

         } catch (const char* msg){
            std::cout << "Hiba: " << msg << "Irj be megfelelo tipust 1-2-3" <<std::endl;
        }
         }


        else if(menu == 5){
            std::cout << "To be done";
        }


        else if(menu == 6){
                std::cout << "\n\tAdios!" << std::endl;
                break;
            }
        else{
                std::cout << "\nNincs ilyen menupont. Valassz ujra!" << std::endl;
        }
    }

*/
///TESZTESETEK
leak();
TEST(Film, ures) {
      Film e = Film("");
      EXPECT_EQ((int)0, e.getHossz()) << "Baj van a hosszaval" << std::endl;
      EXPECT_EQ((int)0, e.getKiadasEv()) << "Baj van a kiadas evevel" << std::endl;
      EXPECT_EQ((std::string)"", e.getCim()) << "Baj van a cimmel" << std::endl;
}ENDM

TEST(Film, konstruktor) {
      Film e = Film("A vak asszony visszanez", 120, 2001);
      EXPECT_EQ((int)120, e.getHossz()) << "Baj van a hosszaval" << std::endl;
      EXPECT_EQ((int)2001, e.getKiadasEv()) << "Baj van a kiadas evevel" << std::endl;
      EXPECT_EQ((std::string)"A vak asszony visszanez", e.getCim()) << "Baj van a cimmel" << std::endl;
}ENDM

TEST(DokumentumFilm, konstruktor) {
      DokumentumFilm e = DokumentumFilm("A vak asszony visszanez", 120, 2001, "Leiras");
      EXPECT_EQ((int)120, e.getHossz()) << "Baj van a hosszaval" << std::endl;
      EXPECT_EQ((int)2001, e.getKiadasEv()) << "Baj van a kiadas evevel" << std::endl;
      EXPECT_EQ((std::string)"A vak asszony visszanez", e.getCim()) << "Baj van a cimmel" << std::endl;
      EXPECT_EQ((std::string)"Leiras", e.getLeiras()) << "Baj van a leirassal" << std::endl;
}ENDM

TEST(CsaladiFilm, konstruktor) {
      CsaladiFilm e = CsaladiFilm("A vak asszony visszanez", 120, 2001, 6);
      EXPECT_EQ((int)120, e.getHossz()) << "Baj van a hosszaval" << std::endl;
      EXPECT_EQ((int)2001, e.getKiadasEv()) << "Baj van a kiadas evevel" << std::endl;
      EXPECT_EQ((std::string)"A vak asszony visszanez", e.getCim()) << "Baj van a cimmel" << std::endl;
      EXPECT_EQ((int)6, e.getKorhatar()) << "Baj van a korhatarral" << std::endl;
}ENDM

TEST(Filmtar, mukodik a filmtarolo tobb filmre) {
      Filmtar<Film> filmtarolo;
      Film e = Film("A kigyo labnyomai", 93, 1979);
      filmtarolo.felvesz(e);
      EXPECT_EQ((int)1, filmtarolo.size()) << "Baj van a filmtar merettel" << std::endl;
      EXPECT_EQ((std::string)"A kigyo labnyomai", filmtarolo[0].getCim()) << "Baj van a filmtarral" << std::endl;

      Film j = Film("A csiga hazamegy", 1, 2003);
      filmtarolo.felvesz(j);
      EXPECT_EQ((int)2, filmtarolo.size()) << "Baj van a filmtar merettel" << std::endl;
      EXPECT_EQ((std::string)"A csiga hazamegy", filmtarolo[1].getCim()) << "Baj van a filmtarral" << std::endl;

}ENDM

TEST(Filmtar, mukodik a filmtarolo mas tipusra is) {
      Filmtar<CsaladiFilm> filmtarolo;
      CsaladiFilm e = CsaladiFilm("A kigyo labnyomai", 93, 1979, 12);
      filmtarolo.felvesz(e);
      EXPECT_EQ((int)1, filmtarolo.size()) << "Baj van a filmtar merettel" << std::endl;
      EXPECT_EQ((std::string)"A kigyo labnyomai", filmtarolo[0].getCim()) << "Baj van a filmtarral" << std::endl;

      CsaladiFilm j = CsaladiFilm("A csiga hazamegy", 1, 2003, 12);
      filmtarolo.felvesz(j);
      EXPECT_EQ((int)2, filmtarolo.size()) << "Baj van a filmtar merettel" << std::endl;
      EXPECT_EQ((std::string)"A csiga hazamegy", filmtarolo[1].getCim()) << "Baj van a filmtarral" << std::endl;

}ENDM

TEST(Filmtar, torles) {
      Filmtar<Film> filmtarolo;
      Film e = Film("A kigyo labnyomai", 93, 1979);
      filmtarolo.felvesz(e);
      filmtarolo.torol(1);
      EXPECT_EQ((int)0, filmtarolo.size()) << "Nem torol a filmtar" << std::endl;
}ENDM

TEST(Filmtar, indexelo op hiba) {
      Filmtar<Film> filmtarolo;
      Film e = Film("A kigyo labnyomai", 93, 1979);
      filmtarolo.felvesz(e);
      EXPECT_THROW(filmtarolo[1], const char*);
}ENDM

TEST(Filmtar, torles indexelo op hiba) {
      Filmtar<Film> filmtarolo;
      Film e = Film("A kigyo labnyomai", 93, 1979);
      filmtarolo.felvesz(e);
      EXPECT_THROW(filmtarolo.torol(2), const char*);
}ENDM


leak();

    return 0;
}

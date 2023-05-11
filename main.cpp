#include <iostream>


#include "memtrace.h"

#include "film.h"
#include "filmtar.hpp"
#include "gtest_lite.h"
#include "string.h"


void leak() { int* ptr = new int; std::cout << ptr; }

int main() {
    std::cout << "Udv a FILMTAR nagyhazimban!" << std::endl;
    leak();

    Filmtar filmtarolo;

//egy par film alapbol van benne, teszt

    Film* e = new Film("A kigyo labnyomai", 93, 1979);
    CsaladiFilm* k = new CsaladiFilm("Piroska es a farkalok", 90, 1995, 6);
    DokumentumFilm* h = new DokumentumFilm("A csigak szexualitasa", 3600, 2006, "Megismerhetjuk ezen csodalatos himnos allatok szaporodasat.");
    DokumentumFilm* cs = new DokumentumFilm("A csiga hazamegy", 1, 2003, "Hat most errol mit mondjak.");
    Film* s = new Film("Star Wars 19: A robotok nemi elete", 69, 2020);

    filmtarolo.felvesz(e);
    filmtarolo.felvesz(s);
    filmtarolo.felvesz(h);
    filmtarolo.felvesz(cs);
    filmtarolo.felvesz(k);


    int menu = 0;

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
        }

        else if(menu == 2){

                String c = "";
                std::cout << "\nAdd meg a keresett film cimet:  ";
                std::cin.ignore();
                cp::getline(std::cin, c);

                bool talalt = false;

                for(size_t i = 0; i < filmtarolo.size(); i++) {
                    if(filmtarolo[i].getCim() == c) {
                        filmtarolo[i].kiir();
                        talalt = true;
                        break;
                    }
                }
                if(!talalt)
                    std::cout << "\n\nNincs ilyen film";


        }


        else if (menu == 3) {
                int tipus;
                std::cout<<"\nMilyen tipusu lesz a felvett film? \n\t\t\t 1 - Film\n\t\t\t 2 - Csaladi film\n\t\t\t 3 - Dokumentumfilm : ";
                std::cin >> tipus;

                if(tipus == 1){
                    Film* ujf = ujf->beolvas();
                    filmtarolo.felvesz(ujf);
                    std::cout<<"\nA modositott filmlista: "<<std::endl;
                    filmtarolo.kiir();

                }

                else if(tipus == 2){
                    CsaladiFilm* ujcs = ujcs->beolvasCsaladi();
                    filmtarolo.felvesz(ujcs);
                    std::cout<<"\nA modositott csaladifilmlista: "<<std::endl;
                    filmtarolo.kiir();

                }
                else if(tipus == 3){
                    DokumentumFilm* ujd = ujd->beolvasDokumentum();
                    filmtarolo.felvesz(ujd);
                    std::cout<<"\nA modositott doksifilmlista: "<<std::endl;
                    filmtarolo.kiir();

                }
            else
                std::cout<< "\n\nNincs ilyen tipus";
}

         else if(menu == 4){

                String c = "";
                std::cout << "\nAdd meg a torolni kivant film cimet:  ";
                std::cin.ignore();
                cp::getline(std::cin, c);

                    for(size_t i = 0; i<filmtarolo.size(); i++){
                        if(filmtarolo[i].getCim() == c){
                            filmtarolo.torol(i);
                        }
                    }
                    std::cout<<"\nA modositott filmlista: "<<std::endl;
                    filmtarolo.kiir();

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


///TESZTESETEK

TEST(Film, ures) {
      Film e = Film("");
      EXPECT_EQ((int)0, e.getHossz()) << "Baj van a hosszaval" << std::endl;
      EXPECT_EQ((int)0, e.getKiadasEv()) << "Baj van a kiadas evevel" << std::endl;
      EXPECT_STREQ("", e.getCim().c_str()) << "Baj van a cimmel" << std::endl;
}ENDM

TEST(Film, konstruktor) {
      Film e = Film("A vak asszony visszanez", 120, 2001);
      EXPECT_EQ((int)120, e.getHossz()) << "Baj van a hosszaval" << std::endl;
      EXPECT_EQ((int)2001, e.getKiadasEv()) << "Baj van a kiadas evevel" << std::endl;
      EXPECT_STREQ("A vak asszony visszanez", e.getCim().c_str()) << "Baj van a cimmel" << std::endl;
}ENDM

TEST(DokumentumFilm, konstruktor) {
      DokumentumFilm e = DokumentumFilm("A vak asszony visszanez", 120, 2001, "Leiras");
      EXPECT_EQ((int)120, e.getHossz()) << "Baj van a hosszaval" << std::endl;
      EXPECT_EQ((int)2001, e.getKiadasEv()) << "Baj van a kiadas evevel" << std::endl;
      EXPECT_STREQ("A vak asszony visszanez", e.getCim().c_str()) << "Baj van a cimmel" << std::endl;
      EXPECT_STREQ("Leiras", e.getLeiras().c_str()) << "Baj van a leirassal" << std::endl;
}ENDM

TEST(CsaladiFilm, konstruktor) {
      CsaladiFilm e = CsaladiFilm("A vak asszony visszanez", 120, 2001, 6);
      EXPECT_EQ((int)120, e.getHossz()) << "Baj van a hosszaval" << std::endl;
      EXPECT_EQ((int)2001, e.getKiadasEv()) << "Baj van a kiadas evevel" << std::endl;
      EXPECT_STREQ("A vak asszony visszanez", e.getCim().c_str()) << "Baj van a cimmel" << std::endl;
      EXPECT_EQ((int)6, e.getKorhatar()) << "Baj van a korhatarral" << std::endl;
}ENDM

TEST(Filmtar, mukodik a filmtarolo 1 filmre) {
      Filmtar filmtarolo;
      Film* e = new Film("A kigyo labnyomai", 93, 1979);
      filmtarolo.felvesz(e);
      EXPECT_EQ((size_t)1, filmtarolo.size()) << "Baj van a filmtar merettel" << std::endl;
      EXPECT_STREQ("A kigyo labnyomai", filmtarolo[0].getCim().c_str()) << "Baj van a filmtarral" << std::endl;
}ENDM

TEST(Filmtar, mukodik a filmtarolo tobb filmre) {
      Filmtar filmtarolo;
      Film* e = new Film("A kigyo labnyomai", 93, 1979);
      filmtarolo.felvesz(e);
      EXPECT_EQ((size_t)1, filmtarolo.size()) << "Baj van a filmtar merettel" << std::endl;
      EXPECT_STREQ("A kigyo labnyomai", filmtarolo[0].getCim().c_str()) << "Baj van a filmtarral" << std::endl;

      Film* j = new Film("A csiga hazamegy", 1, 2003);
      filmtarolo.felvesz(j);
      EXPECT_EQ((size_t)2, filmtarolo.size()) << "Baj van a filmtar merettel" << std::endl;
      EXPECT_STREQ("A csiga hazamegy", filmtarolo[1].getCim().c_str()) << "Baj van a filmtarral" << std::endl;

}ENDM

TEST(Filmtar, mukodik a filmtarolo mas tipusra is) {
      Filmtar filmtarolo;
      CsaladiFilm* e = new CsaladiFilm("A kigyo labnyomai", 93, 1979, 12);
      filmtarolo.felvesz(e);
      EXPECT_EQ((size_t)1, filmtarolo.size()) << "Baj van a filmtar merettel" << std::endl;
      EXPECT_EQ((int)12, e->getKorhatar()) << "Baj van a filmtarral" << std::endl;
      EXPECT_STREQ("A kigyo labnyomai", filmtarolo[0].getCim().c_str()) << "Baj van a filmtarral" << std::endl;

      CsaladiFilm* j = new CsaladiFilm("A csiga hazamegy", 1, 2003, 12);
      filmtarolo.felvesz(j);
      EXPECT_EQ((size_t)2, filmtarolo.size()) << "Baj van a filmtar merettel" << std::endl;
      EXPECT_STREQ("A csiga hazamegy", filmtarolo[1].getCim().c_str()) << "Baj van a filmtarral" << std::endl;

}ENDM

TEST(Filmtar, torles) {
      Filmtar filmtarolo;
      Film* e = new Film("A kigyo labnyomai", 93, 1979);
      filmtarolo.felvesz(e);
      filmtarolo.torol(1);
      EXPECT_EQ((size_t)0, filmtarolo.size()) << "Nem torol a filmtar" << std::endl;
}ENDM

TEST(Filmtar, indexelo op hiba) {
      Filmtar filmtarolo;
      Film* e = new Film("A kigyo labnyomai", 93, 1979);
      filmtarolo.felvesz(e);
      EXPECT_THROW(filmtarolo[1], const char*);
}ENDM

TEST(Filmtar, torles indexelo op hiba) {
      Filmtar filmtarolo;
      Film* e = new Film("A kigyo labnyomai", 93, 1979);
      filmtarolo.felvesz(e);
      EXPECT_THROW(filmtarolo.torol(2), const char*);
}ENDM




    return 0;
}



/* 
 * File:   main.cpp
 * Author: ayşegül
 *
 * Created on November 1, 2022, 6:55 AM
 */

#include <cstdlib>
#include "SatirListesi.hpp"
#include "YoneticiListesi.hpp"
#include "ReadAndAdd.hpp"
#include "DisplayAtConsole.hpp"
#include  "Exception.hpp"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    ReadAndAdd * readingFile = new ReadAndAdd("veriler.txt");

    YoneticiListesi *yoneticiListesi = readingFile->GetFillYoneticiListesi();

    DisplayAtConsole *console = new DisplayAtConsole(yoneticiListesi);
    yoneticiListesi->sortByAverage();
    string karakter = "";
    do {
        console->yazdir_YoneticiListesi();
        cin>>karakter;
        if (karakter == "c") {
            Direction direction = Yukari;
            console->durumuAyarla(direction);
        } else if (karakter == "z") {
            Direction direction = Asagi;
            console->durumuAyarla(direction);
        } else if (karakter == "k") {
            int randomIndex = 0;
            try {
                randomIndex = console->goster_rastgeleSecilenDugum();
            } catch (...) {
                continue;

            }
            cin>>karakter;
            if (karakter == "k") {

                console->sil_rastgeleSecilenDugum(randomIndex);
                yoneticiListesi->sortByAverage();

            }
        } else if (karakter == "p") {
            console->sil_YoneticiNode();
        } else if (karakter == "d") {
            console->sayfaAyarla(YukariSayfa);
        } else if (karakter == "a") {
            console->sayfaAyarla(AsagiSayfa);
        }


    } while (karakter != "q");



    return 0;



}


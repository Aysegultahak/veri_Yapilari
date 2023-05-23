
/* 
 * DOSYA :   DisplayAtConsole.hpp
 * YAZAN : AYŞEGÜL TAHAK
 *
 * 22/11/2022 7.47 tarihinde olusturuldu
 */

#ifndef DISPLAYATCONSOLE_HPP
#define DISPLAYATCONSOLE_HPP

#include "YoneticiListesi.hpp"
#include "ConsolePosition.hpp"


#define DisplayperOnePage 8
#define BeginOffset 0

enum Direction {
    Yukari = 0,
    Asagi = 1,
    Yenile= 2,

};

enum PageDirection {
    YukariSayfa = 0,
    AsagiSayfa = 1,
};

class DisplayAtConsole {
private:
    YoneticiListesi *yonetici;
    int Durum;
    int seteBasla;
    int setiBitir;

    void setler();
public:

    void durumuAyarla(Direction dr);
    void sayfaAyarla(PageDirection pdr);


    DisplayAtConsole(YoneticiListesi* yonetici);

    void yazdir_YoneticiListesi();

    void secileniYazdir_SatirListesi(int x, int y);

    int goster_rastgeleSecilenDugum()throw (IndexOutOfBounds, NoSuchElement);

    void sil_YoneticiNode();

    void sil_rastgeleSecilenDugum(int randomIndex)throw (IndexOutOfBounds, NoSuchElement);
};

#endif /* DISPLAYATCONSOLE_HPP */


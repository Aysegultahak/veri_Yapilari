
#include "DisplayAtConsole.hpp"

DisplayAtConsole::DisplayAtConsole(YoneticiListesi* yonetici) {
    this->yonetici = yonetici;
    if (this->yonetici->Count() < DisplayperOnePage) {
        this->setiBitir = this->yonetici->Count();
    } else {
        this->setiBitir = DisplayperOnePage;
    }

    this->seteBasla = seteBasla;

}

void DisplayAtConsole::setler() {
    int sayfa = Durum / DisplayperOnePage;
    this->seteBasla = DisplayperOnePage*sayfa;
    this->setiBitir = DisplayperOnePage * (sayfa + 1);
    if (this->setiBitir >= this->yonetici->Count()) {
        this->setiBitir = this->yonetici->Count();

    }
}

void DisplayAtConsole::durumuAyarla(Direction dr) {

    if (dr == Yukari) {
        if (Durum >= this->yonetici->Count() - 1) {
            return;
        }
        ++Durum;
        setler();
    } else if (dr == Asagi) {
        if (Durum <= 0) {

            return;
        }
        --Durum;
        setler();
    } else if (dr == Yenile) {
        setler();
    }

}

void DisplayAtConsole::sayfaAyarla(PageDirection pdr) {
    if (pdr == AsagiSayfa) {
        for (int i = 0; i < DisplayperOnePage; ++i) {
            this->durumuAyarla(Asagi);
        }
    } else if (pdr == AsagiSayfa) {
        for (int i = 0; i < DisplayperOnePage; ++i) {
            this->durumuAyarla(Yukari);
        }
    }
}

void DisplayAtConsole::yazdir_YoneticiListesi() {

    int hesap = yonetici->Count();
    system("cls");
    if (hesap == 0) {
        cout << "Goruntulenecek bir Yonetici listesi yok\n";
        exit(1);
        return;
    }


    ConsolePosition.gotoxy(0, 0);
    if (this->seteBasla == 0) {
        cout << "<--ilk--";
    } else {
        cout << "<---geri--";
    }


    int showingNodeCount = this->setiBitir - this->seteBasla;
    showingNodeCount *= 13;


    ConsolePosition.gotoxy(showingNodeCount, 0);


    if (this->setiBitir == yonetici->Count()) {
        cout << "--son-->";
    } else {
        cout << "--ileri-->";
    }
    for (int i = this->seteBasla; i<this->setiBitir; ++i) {


        int mod = i % DisplayperOnePage;
        this->yonetici->printIndex(i, 15 * mod, 1);

    }
    this->secileniYazdir_SatirListesi((this->Durum % DisplayperOnePage) *15, 9);
}

 void DisplayAtConsole::secileniYazdir_SatirListesi(int x, int y) {
        this->yonetici->elementAt(this->Durum)->printSatirListesi(x, y);

    }
  int DisplayAtConsole::goster_rastgeleSecilenDugum()throw (IndexOutOfBounds, NoSuchElement) {

        int randomSelected = this->yonetici->randomGenerator(this->Durum);
        int xPosition = ((this->Durum % DisplayperOnePage) + 1)*15;
        int yPosition = (randomSelected)*6;
        yPosition += 12;
        ConsolePosition.gotoxy(xPosition, yPosition);
        cout << "<--silinecek";
        yPosition = this->yonetici->elementAt(this->Durum)->Count()*6 + 12;

        ConsolePosition.gotoxy(0, yPosition - 1);


        return randomSelected;

    }
  void DisplayAtConsole::sil_YoneticiNode() {
        this->yonetici->removeAt(this->Durum);
       this->durumuAyarla(Yenile);
      
        if(this->Durum==this->setiBitir){
            this->Durum--;
        }
         this->durumuAyarla(Yenile);

   

    }
  void DisplayAtConsole::sil_rastgeleSecilenDugum(int randomIndex)throw (IndexOutOfBounds, NoSuchElement) {
        this->yonetici->randomRemoveAtSatirListesi(this->Durum, randomIndex);
    }

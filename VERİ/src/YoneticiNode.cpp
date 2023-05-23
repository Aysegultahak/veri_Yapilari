
#include "YoneticiNode.hpp"


YoneticiNode::YoneticiNode(SatirListesi* Veri, YoneticiNode *Sonraki , YoneticiNode *Onceki) {
    this->Veri = Veri;
    this->Sonraki = Sonraki;
    this->Onceki = Onceki;
    this->ort = calculateAverage();
}

YoneticiNode::YoneticiNode(SatirListesi* Veri, YoneticiNode *Sonraki ) {
    this->Veri = Veri;
    this->Sonraki = Sonraki;
    this->Onceki = Onceki;
    this->ort = calculateAverage();
}

YoneticiNode::YoneticiNode(SatirListesi* Veri) {
    this->Veri = Veri;
    this->Sonraki = Sonraki;
    this->Onceki = Onceki;
    this->ort = calculateAverage();
}
double YoneticiNode::calculateAverage() {
    double toplam = 0;
    if (this->Veri->isEmpty())
        return toplam;

    int hesap = this->Veri->Count();
    for (int i = 0; i < hesap; ++i) {
        toplam += this->Veri->elementAt(i);
    }
    return toplam / hesap;
}

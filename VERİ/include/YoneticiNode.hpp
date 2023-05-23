

/* 
 * DOSYA:   YoneticiNode.hpp
 * YAZAN: AYŞEGÜL TAHAK
 *
 * 20/11/2022 20:43 tarihinde olusturuldu
 */

#ifndef YONETICINODE_HPP
#define YONETICINODE_HPP


#include "SatirListesi.hpp"

class YoneticiNode {
public:
    SatirListesi* Veri;
    double ort;
    YoneticiNode *Sonraki;
    YoneticiNode *Onceki;

    YoneticiNode(SatirListesi* Veri, YoneticiNode *Sonraki, YoneticiNode *Onceki);
    YoneticiNode(SatirListesi* Veri, YoneticiNode *Sonraki);
    YoneticiNode(SatirListesi* Veri);
    double calculateAverage();
};


#endif /* YONETICINODE_HPP */


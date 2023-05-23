

/* 
 * DOSYA:   SatirListesiNode.hpp
 * YAZAN: AYŞEGÜL TAHAK
 *
 * 18/11/2022 13.10 tarihinde olusturuldu
 */

#ifndef SATIRLISTESINODE_HPP
#define SATIRLISTESINODE_HPP



#include <iostream>
using namespace std;

class SatirListesiNode {
public:
    int Veri;
    SatirListesiNode *Sonraki;
    SatirListesiNode *Onceki;

    SatirListesiNode(const int Veri, SatirListesiNode *Sonraki, SatirListesiNode *Onceki);
    SatirListesiNode(const int Veri, SatirListesiNode *Sonraki);
    SatirListesiNode(const int Veri);
};



#endif /* SATIRLISTESINODE_HPP */


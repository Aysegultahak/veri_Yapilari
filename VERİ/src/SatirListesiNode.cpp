
#include "SatirListesiNode.hpp"

SatirListesiNode::SatirListesiNode(const int Veri, SatirListesiNode *Sonraki , SatirListesiNode *Onceki ) {
    this->Veri = Veri;
    this->Sonraki = Sonraki;
    this->Onceki = Onceki;
}
SatirListesiNode::SatirListesiNode(const int data, SatirListesiNode *Sonraki) {
    this->Veri = Veri;
    this->Sonraki = Sonraki;
    this->Onceki = Onceki;
}
SatirListesiNode::SatirListesiNode(const int Veri) {
    this->Veri = Veri;
    this->Sonraki = Sonraki;
    this->Onceki = Onceki;
}

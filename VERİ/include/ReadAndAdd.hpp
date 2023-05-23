
/* 
 * DOSYA :  ReadAndAdd.hpp
 * YAZAN : AYŞEGÜL TAHAK
 *
 *  21/11/2022 13.34 tarihinde olusturuldu
 */

#ifndef READANDADD_HPP
#define READANDADD_HPP

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

#include "SatirListesi.hpp"
#include "YoneticiListesi.hpp"

class ReadAndAdd {
private:
    std::string dosyaAdi;
    int lineCount();
    SatirListesi **dosyalar;
    void readLine();
public:
    ReadAndAdd(std::string);
    ~ReadAndAdd();
    YoneticiListesi* GetFillYoneticiListesi();



};

#endif /* READANDADD_HPP */


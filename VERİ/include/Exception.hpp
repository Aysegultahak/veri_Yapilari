
/* 
 * DOSYA:   Exception.hpp
 * YAZAN : AYŞEGÜL TAHAK
 *veri yapısı dersi 2. sınıf B grubu
 * aysegul.tahak@sakarya.edu.tr
 *19/11/2022  19.18 tarihinde olusturuldu
 */

#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <iostream>
using namespace std;

class Exception {
private:
    string mesaj;
public:

    Exception(const string &msg) : mesaj(msg) {
    }
    string Mesaj()const;
};


#endif /* EXCEPTION_HPP */


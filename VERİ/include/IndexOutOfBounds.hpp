
/* 
 * DOSYA :  IndexOutOfBounds.hpp
 * YAZAN : AYŞEGÜL TAHAK
 *veri yapısı dersi 2. sınıf B grubu
 * aysegul.tahak@sakarya.edu.tr
 * 21/11/2022 17.39 tarihinde olusturuldu
 */

#ifndef INDEXOUTOFBOUNDS_HPP
#define INDEXOUTOFBOUNDS_HPP
#include "Exception.hpp"

class IndexOutOfBounds : public Exception {
public:

    IndexOutOfBounds(const string &msg) : Exception(msg) {
    }
};


#endif /* INDEXOUTOFBOUNDS_HPP */


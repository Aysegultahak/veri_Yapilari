

/* 
 * DOSYA :   NoSuchElement.hpp
 * YAZAN : AYŞEGÜL TAHAK
 *
 * 19/11/2022 21.56 tarihinde olusturuldu
 */

#ifndef NOSUCHELEMENT_HPP
#define NOSUCHELEMENT_HPP

#include "Exception.hpp"

class NoSuchElement : public Exception {
public:

    NoSuchElement(const string &msg) : Exception(msg) {
    }
};


#endif /* NOSUCHELEMENT_HPP */


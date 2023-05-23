
/* 
 * DOSYA :   ConsolePosition.hpp
 * YAZAN : AYŞEGÜL TAHAK
 *veri yapısı dersi 2. sınıf B grubu
 * aysegul.tahak@sakarya.edu.tr
 * 22/11/2022 11.28
 */

#ifndef CONSOLEPOSITION_HPP
#define CONSOLEPOSITION_HPP

#include <windows.h>

static class ConsolePosition {
public:

    static void gotoxy(int x, int y) {
        COORD c;
        c.X = x;
        c.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
    }


} ConsolePosition;


#endif /* CONSOLEPOSITION_HPP */


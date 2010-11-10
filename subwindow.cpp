#include "subwindow.h"

#include "string.h"

SubWindow::SubWindow(Window* lcd, unsigned int offsetX, unsigned int offsetY, unsigned int width, unsigned int height) {
    _lcd=lcd;
    _offsetX=offsetX;
    _offsetY=offsetY;
    _width=width;
    _height=height;

}

void SubWindow::writeText(unsigned int line, unsigned int pos, char* text) {
    if (line>_height)
        return;

    char* text2=new char[_width-pos+1];
    int i=0;
    while (i<_width-pos+1) {
        text2[i]=text[i];
        if (text[i]=='\0')
            break;
        i++;
    }
    text2[_width-pos]='\0';

    _lcd->writeText(line+_offsetY, pos+_offsetX, text2);
    delete [] text2;
}

void SubWindow::clear() {
    char* spaces=new char[_width+1];
    memset(spaces,32,_width);
    spaces[_width]=0;
    for (int i=0;i<_height;i++) {
        _lcd->writeText(i+_offsetY,_offsetX,spaces);
    }
}
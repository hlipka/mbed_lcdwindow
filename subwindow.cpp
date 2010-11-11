/*
 * mbed LCDWindow library
* Copyright (c) 2010 Hendrik Lipka
* 
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
* 
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
* 
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
* THE SOFTWARE.
*/

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
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

#include "terminal.h"
#include "string.h"

Terminal::Terminal(Window* window) {
    _window=window;
    _height=window->getHeight();
    _width=window->getWidth();
    _lines=new char*[_height];
    for (int i=0;i<_height;i++) {
        _lines[i]=createLine();
    }
}

char* Terminal::createLine()
{
    char* text=new char[_width+1];
    memset(text,32,_width);
    text[_width]=0;
    return text;
}

void Terminal::writeText(unsigned int line, unsigned int pos, char text[]) {
    _window->writeText(line,pos,text);
    int min=pos+strlen(text);
    if (min>_width)
        min=_width;
    for (int i=pos;i<min;i++) {
        _lines[line][i]=text[i-pos]; // copy text into proper line
    }
}

void Terminal::addText(char text[]) {
    delete [] _lines[0];
    for (int i=0;i<_height-1;i++) {
        _lines[i]=_lines[i+1];
    }
    _lines[_height-1]=createLine();
    memset(_lines[_height-1],32,_width);
    int min=strlen(text);
    if (min>_width)
        min=_width;
    for (int i=0;i<min;i++) {
        _lines[_height-1][i]=text[i]; // copy text into proper line
    }
    clear();
    for (int i=0;i<_height;i++) {
        _window->writeText(i,0,_lines[i]);
    }
}

void Terminal::clear() {
    _window->clear();
}

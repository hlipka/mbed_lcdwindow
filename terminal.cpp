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
    _columns=window->getColumns();
    _rows=window->getRows();
    _lineBuffer=new char*[_rows];
    for (int i=0;i<_rows;i++) {
        _lineBuffer[i]=createLine();
    }
}

char* Terminal::createLine()
{
    char* text=new char[_columns+1];
    memset(text,32,_columns);
    text[_columns]=0;
    return text;
}

void Terminal::character(int column, int row, int c)
{
}

void Terminal::writeText(const unsigned int column, const unsigned int row, const char text[]) {
    _window->writeText(column,row,text);
    int min=column+strlen(text);
    if (min>_columns)
        min=_columns;
    for (int i=column;i<min;i++) {
        _lineBuffer[row][i]=text[i-column]; // copy text into proper line
    }
}

void Terminal::addText(const char text[]) {
    delete [] _lineBuffer[0];
    for (int i=0;i<_rows-1;i++) {
        _lineBuffer[i]=_lineBuffer[i+1];
    }
    _lineBuffer[_rows-1]=createLine();
    memset(_lineBuffer[_rows-1],32,_columns);
    int min=strlen(text);
    if (min>_columns)
        min=_columns;
    for (int i=0;i<min;i++) {
        _lineBuffer[_rows-1][i]=text[i]; // copy text into proper line
    }
    clear();
    for (int i=0;i<_rows;i++) {
        _window->writeText(i,0,_lineBuffer[i]);
    }
}

void Terminal::clear() {
    _window->clear();
}

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

SubWindow::SubWindow(Window* lcd, const unsigned int columnOffset, const unsigned int rowOffset, const unsigned int columns, const unsigned int rows) {
    _lcd=lcd;
    _columnOffset=columnOffset;
    _rowOffset=rowOffset;
    _columns=columns;
    _rows=rows;

}

void SubWindow::character(int column, int row, int c)
{
}

void SubWindow::writeText(const unsigned int column, const unsigned int row, const char* text) {
    if (row>_rows)
        return;

    char* text2=new char[_columns-column+1];
    int i=0;
    while (i<_columns-column+1) {
        text2[i]=text[i];
        if (text[i]=='\0')
            break;
        i++;
    }
    text2[_columns-column]='\0';

    _lcd->writeText(column+_columnOffset, row+_rowOffset, text2);
    delete [] text2;
}

void SubWindow::clear() {
    char* spaces=new char[_columns+1];
    memset(spaces,32,_columns);
    spaces[_columns]=0;
    for (int i=0;i<_rows;i++) {
        _lcd->writeText(_columnOffset,_rowOffset+i,spaces);
    }
}
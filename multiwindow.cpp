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

#include "multiwindow.h"

MultiWindow::MultiWindow(vector<Window*> lcds) {
    _lcds=lcds;
    int len=_lcds.size();
    _rows=0;
    for (int i=0;i<len;i++) {
        _rows+=_lcds[i]->getRows();
    }
    _columns=_lcds[0]->getColumns();
}

void MultiWindow::character(int column, int row, int c)
{
}


void MultiWindow::writeText(const unsigned int columns, const unsigned int row, const char text[]) {
    int len=_lcds.size();
    int lines=0;
    for (int i=0;i<len;i++) {
        int height=_lcds[i]->getRows();
        if (row>=lines && row <lines+height) {
            _lcds[i]->writeText(columns,row-lines,text);
        }
        lines+=height;
    }
}

void MultiWindow::clear() {
    int len=_lcds.size();
    for (int i=0;i<len;i++) {
        _lcds[i]->clear();
    }
}

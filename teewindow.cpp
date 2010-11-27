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

#include "teewindow.h"

TeeWindow::TeeWindow(vector<Window*> lcds) {
    _lcds=lcds;
    int len=_lcds.size();
    _columns=_lcds[0]->getColumns();
    _rows=_lcds[0]->getRows();
}

void TeeWindow::character(int column, int row, int c)
{
}

void TeeWindow::writeText(const unsigned int column, const unsigned int row, const char text[]) {
    int len=_lcds.size();
    for (int i=0;i<len;i++) {
        _lcds[i]->writeText(column,row,text);
    }
}

void TeeWindow::clear() {
    int len=_lcds.size();
    for (int i=0;i<len;i++) {
        _lcds[i]->clear();;
    }
}

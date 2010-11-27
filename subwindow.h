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

#ifndef SUBWINDOW_H_
#define SUBWINDOW_H_

#include "window.h"

/**
 * A window class using only a part of a parent window for output.
 * It is assumed that the sub window fill fit into the parent.
*/
class SubWindow: public Window
{
    public:
        /**
         * It is assumed that the sub window fill fit into the parent.
         * @param lcd the parent window
         * @param columnOffset in which column to start the sub window
         * @param rowOffset in which line to start the sub window
         * @param columns the width of the sub window
         * @param rows the height of the sub window
        */
        SubWindow(Window* lcd, const unsigned int columnOffset, const unsigned int rowOffset, const unsigned int columns, const unsigned int rows);
        virtual void writeText(const unsigned int column, const unsigned int row, const char text[]);
        virtual int getColumns(){return _columns;};
        virtual int getRows(){return _rows;};
        /**
         * clear the part of the parent window which is spanned by the sub window.
        */
        virtual void clear();
        
    protected:
        virtual void character(int column, int row, int c);

    private:
        Window* _lcd;
        unsigned int _columnOffset;
        unsigned int _rowOffset;
        unsigned int _columns;
        unsigned int _rows;
};

#endif
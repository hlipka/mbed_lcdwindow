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

#ifndef WINDOW_H_
#define WINDOW_H_

#include "Stream.h"

using namespace mbed;

/**
 * the base window class, which proves the interface for all common methods.
*/
class Window : public Stream {
public:
    /**
     * write text into the window, at the given position.
     * this doesn't change the internal cursor position
     * Implementations should check for the length of the text and shorten it accordingly.
     * @params columns the column where to write
     * @params row the line where to write
     * @params text the text to write
    */
    virtual void writeText(const unsigned int column, const unsigned int row, const char text[])=0;
    /**
     * @param returns the height of the window
    */
    virtual int getRows()=0;
    /**
     * @param returns the width of the window
    */
    virtual int getColumns()=0;
    /**
     * clears the window
    */
    virtual void clear()=0;

    /** 
    * set (internal) cursor to a screen column and row
    *
    * @param column  The horizontal position from the left, indexed from 0
    * @param row     The vertical position from the top, indexed from 0
    */
    virtual void locate(int column, int row);


#if DOXYGEN_ONLY
    /** 
     * Write a character to the LCD, on the position specified by the cursor
     * sets the cursor to the next position, and wraps (from right to left, next line, and from bottom back to top)
     *
     * @param c The character to write to the display
     */
    int putc(int c);

    /** 
     * Write a formated string to the LCD, on the position specified by the cursor
     * does wrap around (as specified by putc)
     *
     * @param format A printf-style format string, followed by the
     *               variables to use in formating the string.
     */
    int printf(const char* format, ...);
#endif
protected:
    // Stream implementation functions
    virtual int _putc(int value);
    virtual int _getc() {
        return -1;
    };
    virtual void character(int column, int row, int c)=0;

    int _column;
    int _row;
};

#endif /*WINDOW_H_*/

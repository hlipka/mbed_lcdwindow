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
         * @param offsetX in which column to start the sub window
         * @param offsetY in which line to start the sub window
         * @param width the width of the sub window
         * @param height the height of the sub window
        */
        SubWindow(Window* lcd, unsigned int offsetX, unsigned int offsetY, unsigned int width, unsigned int height);
        virtual void writeText(unsigned int line, unsigned int pos, char text[]);
        virtual int getHeight(){return _height;};
        virtual int getWidth(){return _width;};
        /**
         * clear the part of the parent window which is spanned by the sub window.
        */
        virtual void clear();
    private:
        Window* _lcd;
        unsigned int _offsetX, _offsetY, _width, _height;
};

#endif
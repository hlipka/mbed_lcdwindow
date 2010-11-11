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

/**
 * the base window class, which proves the interface for all common methods.
*/
class Window
{
    public:
        /**
         * write text into the window, at the given position. 
         * Implementations should check for the length of the text and shorten it accordingly.
         * @params line the line where to write
         * @params pos the column where to write
         * @params text the text to write
        */
        virtual void writeText(unsigned int line, unsigned int pos, char text[])=0;
        /**
         * @param returns the height of the window
        */
        virtual int getHeight()=0;
        /**
         * @param returns the width of the window
        */
        virtual int getWidth()=0;
        /**
         * clears the window
        */
        virtual void clear()=0;
};

#endif /*WINDOW_H_*/

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

#ifndef TEEWINDOW_H_
#define TEEWINDOW_H_

#include "window.h"
#include "vector"

using namespace std;

/**
 * A window class duplicating all writes into all given parent windows (like the Unix 'tee' command).
 * It is assumed that all given windows are of the same size.
*/
class TeeWindow: public Window
{
    public:
        /**
         * @param lcds the vector of windows to write into
        */
        TeeWindow(vector<Window*> lcds);
        /**
         * writes the text to all parent windows
        */
        virtual void writeText(const unsigned int column, const unsigned int row, const char text[]);
        virtual int getColumns(){return _columns;};
        virtual int getRows(){return _rows;};
        /**
         * clears all parent windows
        */
        virtual void clear();
        
    protected:
        virtual void character(int column, int row, int c);

    private:
        vector<Window*> _lcds;
        unsigned int _columns;
        unsigned int _rows;
};

#endif

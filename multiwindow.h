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

#ifndef MULTIWINDOW_H_
#define MULTIWINDOW_H_

#include "window.h"

#include "vector"

using namespace std;

/**
 * Class for combining multiple windows into a single one (by stacking them on top of each other).
 * It is assumed that all windows are of the same width (but they might be of different height).
*/
class MultiWindow: public Window
{
    public:
        /**
         * @param lcds the vector of windows to stack. Aggregated height is calculated as sum of all heights
        */
        MultiWindow(vector<Window*> lcds);
        /**
         * writes text to the parent window which contains the given line
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
        int _columns;
        int _rows;
};

#endif

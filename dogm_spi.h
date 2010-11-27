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

#ifndef DOGM_SPI_H_
#define DOGM_SPI_H_

#include "lcd_spi.h"

#include "DigitalOut.h"
#include "SPI.h"

using namespace mbed; 

/**
 * class for connecting a DOGM16x LCD display, from electronic assembly (www.lcd-module.com )
*/
class DogmLCDSPI: public SPILCDBase
{
    public:
        /**
         * @param columns number of chars per line
         * @param rows number of lines (currently only 1 and 2 work)
         * @param the SPI object used for sending data (set to 1MHz)
         * @param enable the pin name for the enable line (0=active, connected to /CSB)
         * @param rs the pin name for the register select line (0=cmd, 1=data)
        */
        DogmLCDSPI(unsigned int columns, unsigned int rows, SPI *spi, PinName enable, PinName rs); 
        virtual void init();
        virtual void writeText(const unsigned int column, const unsigned int row, const char text[]);
        virtual void clear();
    protected:
        virtual void character(int column, int row, int c);

};

#endif
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

#ifndef LCD_SPI_H_
#define LCD_SPI_H_

#include "lcd.h"

#include "DigitalOut.h"
#include "SPI.h"

using namespace mbed; 

/**
 * base class for all SPI based LCD displays.
 * Provides methods for sending commands and data to the display.
*/
class SPILCDBase: public TextLCDBase
{
    public:
        SPILCDBase(unsigned int columns, unsigned int rows, SPI *spi, PinName enable, PinName rs); 

    protected:
        void sendCmd(const unsigned char byte);
        void sendData(const unsigned char byte);
        
        void sendByte(const unsigned char byte);

        SPI* _spi;
        DigitalOut  *_enable, *_rs;
};

#endif
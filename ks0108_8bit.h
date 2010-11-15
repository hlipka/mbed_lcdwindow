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

#ifndef KS0108_8BIT_H_
#define KS0108_8BIT_H_

#include "lcd.h"

#include "BusOut.h"
#include "DigitalOut.h"

using namespace mbed; 

/**
 * class for connecting graphical KS0108-based LCD-Display (or using similiar controllers)
 * displays are connected in 8bit-mode
 * for displaying ASCII, the vincent font from http://forum.osdev.org/viewtopic.php?f=2&t=22033 is used (courtesy to Quinn Evans)
*/
class KS0108LCD8bit: public TextLCDBase
{
    public:
        /**
         * @param width number of chars per line (using an 8x8 font)
         * @param height number of lines (using an 8x8 font)
         * @param data the bus object used for sending data (must be 8bit)
         * @param enable the pin name for the enable line (1=active)
         * @param rs the pin name for the register select line (0=cmd, 1=data)
         * @param leftCS the pin name for the left display half (1=active)
         * @param rightCS the pin name for the right display half (1=active, use NC for smaller displays)
        */
        KS0108LCD8bit(unsigned int width, unsigned int height, BusOut *data, PinName enable, PinName rs, PinName leftCS, PinName rightCS); 
        virtual void init();
        virtual void writeText(unsigned int line, unsigned int pos, char text[]);
        virtual void clear();

    protected:
        void clearHalf(DigitalOut *cs);

        void sendCmd(unsigned char byte, DigitalOut *cs);
        void sendData(unsigned char byte, DigitalOut *cs);
        
        void sendByte(unsigned char byte, DigitalOut *cs);
        
        void setChar(unsigned int line, unsigned int pos, char c);
        
        BusOut* _data;
        DigitalOut *_enable, *_rs, *_left, *_right;
};
#endif
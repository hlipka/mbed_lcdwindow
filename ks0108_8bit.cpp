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

#include "ks0108_8bit.h"

#include "BusOut.h"
#include "DigitalOut.h"
#include "wait_api.h"
#include "font.h"

#define ENABLE 1

void KS0108LCD8bit::writeText(const unsigned int column, const unsigned int row, const char text[]) {
    int i=0;
    while (text[i]!=0) {
        setChar(column+i, row,text[i]);
        i++;
    }
}

void KS0108LCD8bit::clear() {
    clearHalf(_left);
    if (NULL!=_right)
        clearHalf(_right);
}

void KS0108LCD8bit::clearHalf(DigitalOut* cs) {
    for (int x=0;x<8;x++)
    {
        sendCmd(0xb8|x,cs); 
        wait_us(1);    
        for (int y=0;y<64;y++)
        {
            sendCmd(0x40|y,cs); 
            wait_us(1);    
            sendData(0,cs);
            wait_us(1);    
        }
    }
}

void KS0108LCD8bit::character(int column, int row, int c)
{
    setChar(column,row,c);
}

void KS0108LCD8bit::setChar(const unsigned int column, const unsigned int row, const char c) {
    DigitalOut* cs=NULL;
    int icolumn=column;
    if (icolumn>7)
    {
        cs=_right;
        icolumn-=8;
    }
    else
    {
        cs=_left;
    }
    if (NULL==cs)
        return;
    
    sendCmd(0xb8|row,cs); // set x page    

    unsigned int y=icolumn*8;
    sendCmd(0x40|y,cs); // set start line
    
    // send character data
    for (int i=0;i<8;i++)
    {
        sendData(font_data[c][i],cs);
    }
    
}

KS0108LCD8bit::KS0108LCD8bit
(const unsigned int columns, const unsigned int rows, BusOut *data, const PinName enable, const PinName rs, const PinName leftCS, const PinName rightCS)
        :TextLCDBase(columns, rows) {
    _data=data;
    _rs=new DigitalOut(rs);
    _enable=new DigitalOut(enable);
    _left=new DigitalOut(leftCS);
    _left->write(1-ENABLE);
    if (NC!=rightCS)
    {
        _right=new DigitalOut(rightCS);
        _right->write(1-ENABLE);
    }
    else
        _right=NULL;
    _enable->write(0);
    wait_ms(80);
}

void KS0108LCD8bit::init() {
    sendCmd(0x3f, _left);
    wait_ms(10);
    sendCmd(0xc0, _left);
    
    if (NULL!=_right)
    {
        sendCmd(0x3f, _right);
        wait_ms(10);
        sendCmd(0xc0, _right);
    }
    wait_ms(50);
    clear();
}

void KS0108LCD8bit::sendCmd(const unsigned char cmd, DigitalOut *cs) {
    _rs->write(0);
    wait_us(1);
    sendByte(cmd, cs);
    wait_us(10);
}

void KS0108LCD8bit::sendData(const unsigned char cmd, DigitalOut *cs) {
    _rs->write(1);
    wait_us(1);
    sendByte(cmd, cs);
    wait_us(10);
}

void KS0108LCD8bit::sendByte(const unsigned char byte, DigitalOut *cs) {
    // display reads flags with rising flank of E
    _enable->write(0);
    cs->write(ENABLE);
    _data->write(byte);

    wait_us(2);
    _enable->write(1);

    // display reads data with falling flank of E
    wait_us(2);
    _enable->write(0);

    wait_us(30);
    cs->write(1-ENABLE);
}

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

#include "hd44780_8bit.h"

#include "BusOut.h"
#include "DigitalOut.h"
#include "wait_api.h"


void HD44780LCD8bit::writeText(unsigned int line, unsigned int pos, char text[]) {
//    printf("print to %d,%d {%s}\n",line,pos,text);
    int address=line*0x40+pos;
    sendCmd((unsigned char)address|0x80);
    wait_us(30);

    int i=0;
    while (text[i]!=0) {
        sendData(text[i]);
        wait_us(30);
        i++;
    }
}

void HD44780LCD8bit::clear() {
    sendCmd(1);
}

void HD44780LCD8bit::sendCmd(unsigned char cmd) {
    _rs->write(0);
    wait_us(1);
    sendByte(cmd);
}

void HD44780LCD8bit::sendData(unsigned char cmd) {
    _rs->write(1);
    wait_us(1);
    sendByte(cmd);
}

HD44780LCD8bit::HD44780LCD8bit
(unsigned int width, unsigned int height, BusOut *data, PinName enable, PinName rs)
        :TextLCDBase(width, height)
        {
        _data=data;
        _rs=new DigitalOut(rs);
        _enable=new DigitalOut(enable);
    _enable->write(0);
    wait_ms(80);
}

void HD44780LCD8bit::init() {
    unsigned char initCmd[5]={0x38,0x08,0x01,0x06,0x0c};
    for (int i=0;i<sizeof(initCmd);i++) {
        sendCmd(initCmd[i]);
        wait_ms(50);
    }
}

void HD44780LCD8bit::sendByte(unsigned char byte) {
    _data->write(byte);
    _enable->write(1);
    wait_us(2);
    _enable->write(0);
    wait_us(30);
}


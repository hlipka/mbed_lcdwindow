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

#include "lcd_spi.h"

#include "SPI.h"
#include "DigitalOut.h"
#include "wait_api.h"

SPILCDBase::SPILCDBase
(unsigned int columns, unsigned int rows, SPI *spi, PinName enable, PinName rs)
:TextLCDBase(columns,rows)
{
    _spi=spi;
    _enable=new DigitalOut(enable);
    _rs=new DigitalOut(rs);
    _enable->write(1);
    _spi->format(8,3); // 8 bits, cpol=1, cpha=1 (should be mode 2, but phase seems inverted)
    // set SPI frequency at 0.1 MHz
    _spi->frequency(100000);
}

void SPILCDBase::sendByte(const unsigned char byte)
{
    _enable->write(0); // enable transfer
    wait_us(1);
    _spi->write(byte); // send byte over wire
    wait_us(20);
    _enable->write(1);
}

void SPILCDBase::sendCmd(const unsigned char cmd)
{
    _rs->write(0);
    wait_us(1);
    sendByte(cmd);
    wait_us(1);
    _rs->write(1);
}

void SPILCDBase::sendData(const unsigned char cmd)
{
    _rs->write(1);
    wait_us(1);
    sendByte(cmd);
}

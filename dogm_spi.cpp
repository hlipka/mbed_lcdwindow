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

#include "dogm_spi.h"

#include "SPI.h"
#include "DigitalOut.h"
#include "wait_api.h"

DogmLCDSPI::DogmLCDSPI
(unsigned int width, unsigned int height, SPI *spi, PinName enable, PinName rs)
:SPILCDBase(width,height,spi,enable,rs)
{
}

void DogmLCDSPI::init()
{
    unsigned char initCmd[10]={0x38,0x39,0x14,0x55,0x6d,0x78,0x38,0x0c,0x01,0x06};
    
    _enable->write(1);
    wait_ms(80);
    
    for (int i=0;i<sizeof(initCmd);i++)
    {
        sendCmd(initCmd[i]);
        wait_ms(4);
    }
}

void DogmLCDSPI::writeText(unsigned int line, unsigned int pos, char text[])
{
    int address=(line)*0x40+(pos);
    sendCmd((char)address|0x80);
    wait_ms(1);
    
    int i=0;
    while(text[i]!=0)
    {
        sendData(text[i]);
        wait_ms(1);
        i++;
    }
}

void DogmLCDSPI::clear()
{
    sendCmd(1);
}


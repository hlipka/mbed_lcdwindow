#include "lcd_spi.h"

#include "SPI.h"
#include "DigitalOut.h"
#include "wait_api.h"

SPILCDBase::SPILCDBase
(unsigned int width, unsigned int height, SPI *spi, PinName enable, PinName rs)
:TextLCDBase(width,height)
{
    _spi=spi;
    _enable=new DigitalOut(enable);
    _rs=new DigitalOut(rs);
    _enable->write(1);
    _spi->format(8,3); // 8 bits, cpol=1, cpha=1 (should be mode 2, but phase seems inverted)
    // set SPI frequency at 0.1 MHz
    _spi->frequency(100000);
}

void SPILCDBase::sendByte(unsigned char byte)
{
    _enable->write(0); // enable transfer
    wait_us(1);
    _spi->write(byte); // send byte over wire
    wait_us(20);
    _enable->write(1);
}

void SPILCDBase::sendCmd(unsigned char cmd)
{
    _rs->write(0);
    wait_us(1);
    sendByte(cmd);
    wait_us(1);
    _rs->write(1);
}

void SPILCDBase::sendData(unsigned char cmd)
{
    _rs->write(1);
    wait_us(1);
    sendByte(cmd);
}

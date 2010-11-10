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


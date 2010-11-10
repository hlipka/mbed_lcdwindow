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
        SPILCDBase(unsigned int width, unsigned int height, SPI *spi, PinName enable, PinName rs); 

    protected:
        void sendCmd(unsigned char byte);
        void sendData(unsigned char byte);
        
        void sendByte(unsigned char byte);

        SPI* _spi;
        DigitalOut  *_enable, *_rs;
};

#endif
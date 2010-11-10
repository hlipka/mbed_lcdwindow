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
         * @param width number of chars per line
         * @param height number of lines (currently only 1 and 2 work)
         * @param the SPI object used for sending data (set to 1MHz)
         * @param enable the pin name for the enable line (0=active, connected to /CSB)
         * @param rs the pin name for the register select line (0=cmd, 1=data)
        */
        DogmLCDSPI(unsigned int width, unsigned int height, SPI *spi, PinName enable, PinName rs); 
        virtual void init();
        virtual void writeText(unsigned int line, unsigned int pos, char text[]);
        virtual void clear();
};

#endif
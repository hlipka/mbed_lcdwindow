#ifndef HD44780_8BIT_H_
#define HD44780_8BIT_H_

#include "lcd.h"

#include "BusOut.h"
#include "DigitalOut.h"

using namespace mbed; 

/**
 * class for connecting HD44780-based LCD-Display (or using similiar controllers)
 * displays are connected in 8bit-mode
 * currently only 1 or 2 lines are supported
*/
class HD44780LCD8bit: public TextLCDBase
{
    public:
        /**
         * @param width number of chars per line
         * @param height number of lines (currently only 1 and 2 work)
         * @param data the bus object used for sending data (must be 8bit)
         * @param enable the pin name for the enable line (1=active)
         * @param rs the pin name for the register select line (0=cmd, 1=data)
        */
        HD44780LCD8bit(unsigned int width, unsigned int height, BusOut *data, PinName enable, PinName rs); 
        virtual void init();
        virtual void writeText(unsigned int line, unsigned int pos, char text[]);
        virtual void clear();

    protected:
        void sendCmd(unsigned char byte);
        void sendData(unsigned char byte);
        
        void sendByte(unsigned char byte);
        
        BusOut* _data;
        DigitalOut *_enable, *_rs;
};
#endif
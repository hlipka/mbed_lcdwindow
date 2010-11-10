#ifndef LCD_H_
#define LCD_H_

#include "window.h"

/**
 * base class for all (text based) LCD displays
*/
class TextLCDBase: public Window
{
    public:
        /**
         * this is the only function added to the Window interface
         * it must be called from the outside, and initializes the display.
        */
        virtual void init()=0;
        virtual int getHeight(){return _height;};
        virtual int getWidth(){return _width;};
    protected:
        const unsigned int _width, _height;
        TextLCDBase(unsigned int width, unsigned int height):_width(width),_height(height)
        {
        } 
};

#endif /*LCD_H_*/

#ifndef SUBWINDOW_H_
#define SUBWINDOW_H_

#include "window.h"

/**
 * A window class using only a part of a parent window for output.
 * It is assumed that the sub window fill fit into the parent.
*/
class SubWindow: public Window
{
    public:
        /**
         * It is assumed that the sub window fill fit into the parent.
         * @param lcd the parent window
         * @param offsetX in which column to start the sub window
         * @param offsetY in which line to start the sub window
         * @param width the width of the sub window
         * @param height the height of the sub window
        */
        SubWindow(Window* lcd, unsigned int offsetX, unsigned int offsetY, unsigned int width, unsigned int height);
        virtual void writeText(unsigned int line, unsigned int pos, char text[]);
        virtual int getHeight(){return _height;};
        virtual int getWidth(){return _width;};
        /**
         * clear the part of the parent window which is spanned by the sub window.
        */
        virtual void clear();
    private:
        Window* _lcd;
        unsigned int _offsetX, _offsetY, _width, _height;
};

#endif
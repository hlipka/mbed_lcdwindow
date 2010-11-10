#ifndef TERMINAL_H_
#define TERMINAL_H_

#include "window.h"

/**
 * A windows class which uses an internal buffer to provide automatic scrolling.
 * The buffer is initially filled with spaces.
*/
class Terminal: public Window
{
    public:
        /**
         * @param window the parent window
        */
        Terminal(Window* window);
        /**
         * works like the normal writeText method, 
         * but also stores the written text into the internal buffer (which makes it subject to scrolling)
        */
        virtual void writeText(unsigned int line, unsigned int pos, char text[]);
        /**
         * write the given text into the last line (at the first position)
         * @param text the text to write
        */
        virtual void addText(char text[]);
        virtual int getHeight(){return _height;};
        virtual int getWidth(){return _width;};
        virtual void clear();
    private:
        Window* _window;
        char** _lines;
        int _height, _width;
        char* createLine();
};

#endif
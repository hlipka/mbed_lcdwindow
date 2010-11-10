#ifndef WINDOW_H_
#define WINDOW_H_

/**
 * the base window class, which proves the interface for all common methods.
*/
class Window
{
    public:
        /**
         * write text into the window, at the given position. 
         * Implementations should check for the length of the text and shorten it accordingly.
         * @params line the line where to write
         * @params pos the column where to write
         * @params text the text to write
        */
        virtual void writeText(unsigned int line, unsigned int pos, char text[])=0;
        /**
         * @param returns the height of the window
        */
        virtual int getHeight()=0;
        /**
         * @param returns the width of the window
        */
        virtual int getWidth()=0;
        /**
         * clears the window
        */
        virtual void clear()=0;
};

#endif /*WINDOW_H_*/

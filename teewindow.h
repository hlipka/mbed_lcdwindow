#ifndef TEEWINDOW_H_
#define TEEWINDOW_H_

#include "window.h"
#include "vector"

using namespace std;

/**
 * A window class duplicating all writes into all given parent windows (like the Unix 'tee' command).
 * It is assumed that all given windows are of the same size.
*/
class TeeWindow: public Window
{
    public:
        /**
         * @param lcds the vector of windows to write into
        */
        TeeWindow(vector<Window*> lcds);
        /**
         * writes the text to all parent windows
        */
        virtual void writeText(unsigned int line, unsigned int pos, char text[]);
        virtual int getHeight(){return _height;};
        virtual int getWidth(){return _width;};
        /**
         * clears all parent windows
        */
        virtual void clear();
    private:
        vector<Window*> _lcds;
        int _height,_width;
};

#endif

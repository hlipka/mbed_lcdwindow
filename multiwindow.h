#ifndef MULTIWINDOW_H_
#define MULTIWINDOW_H_

#include "window.h"

#include "vector"

using namespace std;

/**
 * Class for combining multiple windows into a single one (by stacking them on top of each other).
 * It is assumed that all windows are of the same width (but they might be of different height).
*/
class MultiWindow: public Window
{
    public:
        /**
         * @param lcds the vector of windows to stack. Aggregated height is calculated as sum of all heights
        */
        MultiWindow(vector<Window*> lcds);
        /**
         * writes text to the parent window which contains the given line
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

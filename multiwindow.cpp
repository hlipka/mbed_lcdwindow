#include "multiwindow.h"

MultiWindow::MultiWindow(vector<Window*> lcds) {
    _lcds=lcds;
    int len=_lcds.size();
    _height=0;
    for (int i=0;i<len;i++) {
        _height+=_lcds[i]->getHeight();
    }
    _width=_lcds[0]->getWidth();
}

void MultiWindow::writeText(unsigned int line, unsigned int pos, char text[]) {
    int len=_lcds.size();
    int lines=0;
    for (int i=0;i<len;i++) {
        int height=_lcds[i]->getHeight();
        if (line>=lines && line <lines+height) {
            _lcds[i]->writeText(line-lines,pos,text);
        }
        lines+=height;
    }
}

void MultiWindow::clear() {
    int len=_lcds.size();
    for (int i=0;i<len;i++) {
        _lcds[i]->clear();
    }
}

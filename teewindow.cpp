#include "teewindow.h"

TeeWindow::TeeWindow(vector<Window*> lcds) {
    _lcds=lcds;
    int len=_lcds.size();
    _height=_lcds[0]->getHeight();
    _width=_lcds[0]->getWidth();
}

void TeeWindow::writeText(unsigned int line, unsigned int pos, char text[]) {
    int len=_lcds.size();
    for (int i=0;i<len;i++) {
        _lcds[i]->writeText(line,pos,text);
    }
}

void TeeWindow::clear() {
    int len=_lcds.size();
    for (int i=0;i<len;i++) {
        _lcds[i]->clear();;
    }
}

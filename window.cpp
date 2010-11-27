#include "window.h"

void Window::locate(int column, int row) {
    _column = column;
    _row = row;
}

int Window::_putc(int value) {
    if (value == '\n') {
        _column = 0;
        _row++;
        if (_row >= getRows()) {
            _row = 0;
        }
    } else {
        character(_column, _row, value);
        _column++;
        if (_column >= getColumns()) {
            _column = 0;
            _row++;
            if (_row >= getRows()) {
                _row = 0;
            }
        }
    }
    return value;
}
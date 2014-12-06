#ifndef _RECT_H_
#define _RECT_H_

#include "position.h"

class Rect
{
public:
    Position pos;
    Position size;

    Rect() {} 
    Rect(short x, short y, short w, short h): pos(x, y), size(w, h) {}
};
#endif // _RECT_H_

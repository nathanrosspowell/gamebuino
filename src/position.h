#ifndef _POSITION_H_
#define _POSITION_H_
class Position
{
public:
    short x;
    short y;

    Position() : x(0), y(0) {}
    Position(short x, short y): x(x), y(y) {}

    void draw();
};
#endif // _POSITION_H_

#ifndef _LEVEL_H_
#define _LEVEL_H_
class Level
{
public:
    short x;
    short y;

    Level() : x(0), y(0) {}
    Level(short x, short y): x(x), y(y) {}

    void draw();
};
#endif // _LEVEL_H_

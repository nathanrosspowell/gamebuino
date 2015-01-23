#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "position.h"

class Player
{
public:
    Position pos;
    Rect head;
    Rect body;
    Rect legs;
    Rect bounds;
    short jumpForce;
    bool startLevel;

    Player() 
        : pos ()
        , head( 2, 0, 2, 2 )
        , body(0, 2, 6, 8 )
        , legs( 2, 10, 2, 8 )
        , bounds( 0, 0, 6, 18 )
        , jumpForce( 0.0f )
        , startLevel( false )
    {
    }
};
#endif // _PLAYER_H_

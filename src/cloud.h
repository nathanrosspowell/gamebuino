#ifndef _CLOUD_H_
#define _CLOUD_H_

#include "position.h"

class Cloud
{
public:
    Position pos;
    short size;
    short speed;

    Cloud() : pos(), size( 0 ), speed( 0 ) {} 
};
#endif // _CLOUD_H_

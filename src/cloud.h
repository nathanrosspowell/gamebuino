#ifndef _CLOUD_H_
#define _CLOUD_H_

#include "position.h"

class Cloud
{
public:
    Position pos;
    short size;
    short delay;

    Cloud() : pos(), size( 0 ), delay( 0 ) {} 
};
#endif // _CLOUD_H_

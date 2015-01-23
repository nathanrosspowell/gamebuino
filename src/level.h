#ifndef _LEVEL_H_
#define _LEVEL_H_

#include "cloud.h"

#define NUM_CLOUDS 4
#define NUM_SEPERATORS 4

class Level
{
public:
    Cloud clouds[NUM_CLOUDS];
    short seperators[NUM_SEPERATORS];
    short introDisplay;

    Level() : introDisplay( 20 )
    {
        // Seperators
        for ( short i = 0; i < NUM_SEPERATORS; ++i )
        {
            seperators[ i ] = ( 84 / NUM_SEPERATORS ) * i;
        }
    }
};
#endif // _LEVEL_H_

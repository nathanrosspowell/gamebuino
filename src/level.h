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
    short seperatorSpeed;
    short introDisplay;

    Level() 
        : seperatorSpeed( 2 )
        , introDisplay( 20 )
    {
        // Shuffle indicies.
        short randoms[ NUM_CLOUDS ];
        for ( short i = 0; i < NUM_CLOUDS; ++i )
        {
            randoms[ i ] = i;
        }
        for ( short i = 0; i < NUM_CLOUDS; ++i )
        {
            short x = random(0, NUM_CLOUDS);
            short y = random(0, NUM_CLOUDS);
            short temp = randoms[ x ];
            randoms[ x ] = randoms[ y ];
            randoms[ y ] = temp;
        }
        // Clouds.
        for ( short i = 0; i < NUM_CLOUDS; ++i )
        {
            Cloud& cloud = clouds[ i ];
            cloud.size = 3 + ( 2 * randoms[ i ] );
            cloud.pos.x = ( 84 / NUM_SEPERATORS ) * cloud.size;
            cloud.pos.y = cloud.size + ( i * 3 );
            cloud.speed = 1 + ( randoms[ i ] % 2 );

        }
        // Seperators are evenly spaced.
        for ( short i = 0; i < NUM_SEPERATORS; ++i )
        {
            seperators[ i ] = ( 84 / NUM_SEPERATORS ) * i;
        }
    }
};
#endif // _LEVEL_H_

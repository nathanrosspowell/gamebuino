#ifndef _LEVEL_H_
#define _LEVEL_H_

#include "cloud.h"
#include "level_object.h"

#define NUM_CLOUDS 4
#define NUM_SEPERATORS 4
#define MIN_LEVEL_OBJECTS 3 
#define MAX_LEVEL_OBJECTS 5

class Level
{
public:
    LevelObject levelObjects[MAX_LEVEL_OBJECTS];
    Cloud clouds[NUM_CLOUDS];
    short seperators[NUM_SEPERATORS];
    short speed;
    short introDisplay;
    short numObjects;
    int frameProgress;

    Level() 
        : speed( 1 )
        , introDisplay( 20 )
        , numObjects( 0 )
        , frameProgress( 0 )
    {
        setupSeperators();
        setupClouds();
        setupObjects();
    }

private:
    void setupSeperators()
    {
        // Seperators are evenly spaced.
        for ( short i = 0; i < NUM_SEPERATORS; ++i )
        {
            seperators[ i ] = ( 84 / NUM_SEPERATORS ) * i;
        }
    }

    void setupClouds()
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
            cloud.speed = 1 + ( randoms[ i ] % 3 );
        }
    }

    void setupObjects()
    {
        int offset = 84;
        numObjects = random( MIN_LEVEL_OBJECTS, MAX_LEVEL_OBJECTS );
        for ( short i = 0; i < numObjects; ++i )
        {
            offset = offset + random( 5, 15 ) * 5;
            int type = random(0, LevelObjectType::MAX);
            levelObjects[ i ] = LevelObject( offset, (LevelObjectType::Enum)type );
        }

    }
};
#endif // _LEVEL_H_

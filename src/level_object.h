#ifndef _LEVEL_OBJECT_H_
#define _LEVEL_OBJECT_H_

#include "cloud.h"

#define NUM_CLOUDS 4
#define NUM_SEPERATORS 4
#define MIN_LEVEL_OBJECTS 10
#define MAX_LEVEL_OBJECTS 64

struct LevelObjectType
{
    enum Enum
    {
        Gap,
        StepUp,
        StepDown,
        Jumpable,
        Kickable,

        MAX
    };
};

class LevelObject
{
public:
    short offset;
    LevelObjectType::Enum type;
    
    LevelObject() : offset( 0 ), type( LevelObjectType::MAX ) {}
    LevelObject( short offset, LevelObjectType::Enum type )
        : offset( offset )
        , type( type )
    {
    }
};
#endif // _LEVEL_OBJECT_H_

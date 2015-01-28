#ifndef _LEVEL_OBJECT_H_
#define _LEVEL_OBJECT_H_

#include "cloud.h"

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
    int offset;
    LevelObjectType::Enum type;
    
    LevelObject() : offset( 0 ), type( LevelObjectType::MAX ) {}
    LevelObject( int off, LevelObjectType::Enum type )
        : offset( off )
        , type( type )
    {
    }
};
#endif // _LEVEL_OBJECT_H_

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

    char GetIcon() {
        char c = ' ';
        switch( type ) {
            case LevelObjectType::Gap: c = 'g'; break;
            case LevelObjectType::StepUp: c = 'u'; break;
            case LevelObjectType::StepDown: c = 'd'; break;
            case LevelObjectType::Jumpable: c = 'j'; break;
            case LevelObjectType::Kickable: c = 'k'; break;
        }
        return c;
    }
};
#endif // _LEVEL_OBJECT_H_

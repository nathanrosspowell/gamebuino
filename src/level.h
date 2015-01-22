#ifndef _LEVEL_H_
#define _LEVEL_H_

#include "cloud.h"

#define NUM_CLOUDS 4

class Level
{
public:
    Cloud clouds[NUM_CLOUDS];

    Level() {}
};
#endif // _LEVEL_H_

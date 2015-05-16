//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void draw( Rect& rect ) {
    g_gb.display.fillRect(rect.pos.x, rect.pos.y, rect.size.x, rect.size.y );
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void draw( Level& level ) {
    const bool debug = false;
    const short floorStart = 42;
    const short floorWidth = 4;
    g_gb.display.print(F("Frame:"));
    g_gb.display.print(level.frameProgress);
    // Level Debug
    if ( debug ) {
        for ( short i = 0; i < level.numObjects; ++i ) {
            LevelObject& obj = level.levelObjects[ i ];
            {
                g_gb.display.cursorX = 39; 
                g_gb.display.cursorY = 6 * i;
                g_gb.display.print("i");
                g_gb.display.print(i);
            }
            {
                g_gb.display.cursorX = 49;
                g_gb.display.cursorY = 6 * i;
                g_gb.display.print("o");
                g_gb.display.print(obj.offset);
            }
            {
                g_gb.display.cursorX = 66;
                g_gb.display.cursorY = 6 * i;
                g_gb.display.print(obj.GetIcon());
            }
        }

    }
    // Floor.
    g_gb.display.drawFastHLine(0, floorStart, 84 );
    g_gb.display.drawFastHLine(0, floorStart + floorWidth, 84 );
    // Foor seperators.
    for ( short i = 0; i < NUM_SEPERATORS; ++i )
    {
        short seperator = level.seperators[i];
        for ( short p = 1; p < floorWidth; ++p )
        {
            g_gb.display.drawPixel( seperator + p, floorStart + p );
        }
    }
    // Clouds.
    for ( short i = 0; i < NUM_CLOUDS; ++i )
    {
        Cloud& cloud = level.clouds[i];
        if ( cloud.size != 0 )
        {
            g_gb.display.drawCircle( cloud.pos.x, cloud.pos.y, cloud.size );
        }
    }
    // Intro.
    if ( g_p1.startLevel && level.introDisplay > 0 )
    {
        g_gb.display.cursorX = 5;
        g_gb.display.cursorY = 5;
        g_gb.display.print(F("GO!"));
        level.introDisplay -= 1;
    }
    else if ( level.introDisplay < 1 )
    {
        // Draw objects
        bool passedAllObjects = true;
        int f = level.frameProgress;
        for ( short i = 0; i < level.numObjects; ++i ) {
            LevelObject& obj = level.levelObjects[ i ];
            draw( obj, f );
            int x = obj.offset - f;
            if ( x > -10 && x < 95 ) {
                passedAllObjects = false;
                if ( debug ) {
                    g_gb.display.cursorX = x;
                    g_gb.display.cursorY = 15;
                    g_gb.display.print(i);
                    g_gb.display.cursorX = x;
                    g_gb.display.cursorY = 22;
                    g_gb.display.print(obj.offset);
                }
            }
        }
        if ( f > 200 && passedAllObjects ) {
            g_gb.display.cursorX = 15;
            g_gb.display.cursorY = 15;
            g_gb.display.print("CONGRATS!!");
        }

    }

}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void draw( Player& p1 ) {
    Rect head = p1.head + p1.pos;
    Rect body = p1.body + p1.pos;
    Rect legs = p1.legs + p1.pos;
    draw( head );
    draw( body );
    draw( legs );
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void draw( LevelObject& obj, int f ){
    int x = obj.offset - f;
    if ( x > -10 && x < 95 )
    {
        switch ( obj.type ) {
            //case  LevelObjectType::Gap: break;
            //case  LevelObjectType::StepUp: break;
            //case  LevelObjectType::StepDown: break;
            case  LevelObjectType::Jumpable: { 
                    g_gb.display.fillRect(x, 36, 8, 8);
                }
                break;
            //case  LevelObjectType::Kickable: break;
            default:
                g_gb.display.cursorX = x;
                g_gb.display.cursorY = 39;
                g_gb.display.print(obj.GetIcon());
                break;
        }
    }
}


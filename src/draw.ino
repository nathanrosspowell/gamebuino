//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void draw( Rect& rect )
{
    g_gb.display.fillRect(rect.pos.x, rect.pos.y, rect.size.x, rect.size.y );
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void draw( Level& level )
{
    g_gb.display.print(F("Frame:"));
    g_gb.display.print(level.frameProgress);
    const short floorStart = 42;
    const short floorWidth = 4;
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
        int f = level.frameProgress;
        for ( short i = 0; i < level.numObjects; ++i )
        {
            LevelObject& obj = level.levelObjects[ i ];
            char c = ' ';
            switch( obj.type )
            {
            case LevelObjectType::Gap: c = 'g'; break;
            case LevelObjectType::StepUp: c = 'u'; break;
            case LevelObjectType::StepDown: c = 'd'; break;
            case LevelObjectType::Jumpable: c = 'j'; break;
            case LevelObjectType::Kickable: c = 'k'; break;
            }
            int x = obj.offset - f;
            if ( x > -10 && x < 95 )
            {
                g_gb.display.cursorX = x;
                g_gb.display.cursorY = 15;
                g_gb.display.print(i);
                g_gb.display.cursorX = x;
                g_gb.display.cursorY = 22;
                g_gb.display.print(obj.offset);
                g_gb.display.cursorX = x;
                g_gb.display.cursorY = 38;
                g_gb.display.print(c);
            }
            //g_gb.display.drawChar( obj.offset - x, floorStart - 9, c, 1 ); 
        }

    }

}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void draw( Player& p1 )
{
    Rect head = p1.head + p1.pos;
    Rect body = p1.body + p1.pos;
    Rect legs = p1.legs + p1.pos;
    draw( head );
    draw( body );
    draw( legs );
}


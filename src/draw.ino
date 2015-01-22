//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void draw( Rect& rect )
{
    g_gb.display.fillRect(rect.pos.x, rect.pos.y, rect.size.x, rect.size.y );
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void draw( Level& level )
{
    // Floor.
    g_gb.display.drawFastHLine(0, 46, 84 );
    g_gb.display.drawFastHLine(0, 42, 84 );
    // 'Clouds'
    for ( short i = 0; i < NUM_CLOUDS; ++i )
    {
        Cloud& cloud = level.clouds[i];
        if ( cloud.size != 0 )
        {
            g_gb.display.drawCircle( cloud.pos.x, cloud.pos.y, cloud.size );
        }
    }

       
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void draw( Player& player )
{
    Rect head = player.head + player.pos;
    Rect body = player.body + player.pos;
    Rect legs = player.legs + player.pos;
    draw( head );
    draw( body );
    draw( legs );
}


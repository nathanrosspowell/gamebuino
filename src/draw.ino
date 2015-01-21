void draw( Rect& rect )
{
    g_gb.display.fillRect(rect.pos.x, rect.pos.y, rect.size.x, rect.size.y );
}

void draw( Level& level )
{
    // Floor.
    g_gb.display.fillRect(0, 45, 84, 1 );
}

void draw( Player& player )
{
    Rect head = player.head + player.pos;
    Rect body = player.body + player.pos;
    Rect legs = player.legs + player.pos;
    draw( head );
    draw( body );
    draw( legs );
}


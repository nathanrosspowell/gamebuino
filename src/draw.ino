void draw( Rect& rect )
{
    g_gb.display.fillRect(rect.pos.x, rect.pos.y, 1, 1 );
}

void draw( Level& level )
{
    // Floor.
    g_gb.display.fillRect(0, 45, 84, 1 );
}

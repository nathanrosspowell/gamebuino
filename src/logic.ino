void move( Player& p1 )
{
    /*
    else if (g_gb.buttons.repeat(BTN_RIGHT, 1))
    {
        p1.pos.x += 1;
    }
    else if (g_gb.buttons.repeat(BTN_DOWN, 1))
    {
        p1.pos.y += 1;
    }
    else if (g_gb.buttons.repeat(BTN_LEFT, 1))
    {
        p1.pos.x -= 1;
    }
    */
    const short maxHeight = 45 - p1.bounds.size.y;
    // Clamp
    if ( p1.pos.y > maxHeight )
    {
        p1.pos.y = maxHeight;
    }

    if ( p1.pos.y == maxHeight )
    {
        if (g_gb.buttons.repeat(BTN_UP, 1))
        {
            p1.pos.y -= 10;
        }
    }
    else
    {
        p1.pos.y += 1;
    }
}

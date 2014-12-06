void move( Rect& rect )
{
    if (g_gb.buttons.repeat(BTN_UP, 1))
    {
        rect.pos.y -= 1;
    }
    else if (g_gb.buttons.repeat(BTN_RIGHT, 1))
    {
        rect.pos.x += 1;
    }
    else if (g_gb.buttons.repeat(BTN_DOWN, 1))
    {
        rect.pos.y += 1;
    }
    else if (g_gb.buttons.repeat(BTN_LEFT, 1))
    {
        rect.pos.x -= 1;
    }
}

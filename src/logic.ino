void move( Player& p1 )
{
    if (g_gb.buttons.repeat(BTN_UP, 1))
    {
        p1.pos.y -= 1;
    }
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
}

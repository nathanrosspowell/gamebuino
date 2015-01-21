void move( Player& p1 )
{
    const short maxJump = 10;
    const short fakeGrav = 2;
    const short maxHeight = 45 - p1.bounds.size.y;
    // Clamp
    if ( p1.pos.y > maxHeight )
    {
        p1.pos.y = maxHeight;
    }
    // Jump.
    if ( p1.pos.y == maxHeight )
    {
        p1.jumpForce = 0;
        if (g_gb.buttons.repeat(BTN_UP, 1))
        {
            p1.jumpForce = maxJump;
        }
    }
    // Gravity.
    if ( p1.jumpForce > 0 )
    {
        p1.pos.y -= p1.jumpForce;
        p1.jumpForce -= fakeGrav;
    }
    if ( p1.pos.y != maxHeight )
    {
        p1.pos.y += fakeGrav;
    }

}

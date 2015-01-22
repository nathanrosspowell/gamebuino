//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void move( Player& p1 )
{
    const short maxJump = 8;
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

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void move( Level& level )
{
    for ( short i = 0; i < NUM_CLOUDS; ++i )
    {
        Cloud& cloud = level.clouds[i];
        if ( cloud.size == 0 )
        {
            cloud.size = 3 + ( i * 2 );// randomise later
            cloud.pos.x = 84 + cloud.size;
            cloud.pos.y = cloud.size + ( i * 5 );
            cloud.delay = i * NUM_CLOUDS * 5;
        }
        else if ( cloud.pos.x < ( 0 - cloud.size ) )
        {
            cloud.size = 0;
        }
        else if ( cloud.delay > 0 )
        {
            cloud.delay -= 1;
        }
        else 
        {
            cloud.pos.x -= 1;
        }
    }
}

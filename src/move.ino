//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void move( Player& p1 )
{
    const short maxJump = 8;
    const short fakeGrav = 2;
    const short introBound =  15;
    const short floorBound = 45 - p1.bounds.size.y;

    if ( p1.startLevel == false )
    {
        if ( p1.pos.x < introBound )
        {
            p1.pos.x += 1;
        }
        else
        {
            p1.pos.x = introBound;
            p1.startLevel = true;
        }
    }
    // Clamp
    if ( p1.pos.y > floorBound )
    {
        p1.pos.y = floorBound;
    }
    // Jump.
    if ( p1.pos.y == floorBound )
    {
        p1.jumpForce = 0;
        if ( p1.startLevel && g_gb.buttons.repeat(BTN_UP, 1))
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
    if ( p1.pos.y != floorBound )
    {
        p1.pos.y += fakeGrav;
    }
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void moveClouds( Level& level )
{
    // Clouds.
    for ( short i = 0; i < NUM_CLOUDS; ++i )
    {
        Cloud& cloud = level.clouds[i];
        // Reset to the right
        if ( cloud.pos.x < ( 0 - cloud.size ) )
        {
            cloud.pos.x = 84 + cloud.size;
        }
        else 
        {
            cloud.pos.x -= cloud.speed;
        }
    }
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void moveSeperators( Level& level )
{
    for ( short i = 0; i < NUM_SEPERATORS; ++i )
    {
        short& seperator = level.seperators[ i ];
        if ( seperator > 0 )
        {
            seperator -= level.seperatorSpeed;
        }
        else
        {
            seperator = 84;
        }
    }

}

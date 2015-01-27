//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//imports the SPI library (needed to communicate with Gamebuino's screen)
#include <SPI.h>
//importe the Gamebuino library
#include <Gamebuino.h>

#include "rect.h"
#include "level.h"
#include "player.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//creates a Gamebuino object named g_gb
Gamebuino g_gb = Gamebuino();
//declare all the sprites which are in the "sprites" tab
//extern const byte PROGMEM logo[];

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Game variables.

// Render.
const short g_fps = 20;

// State.
bool g_firstRun = true;

// Character controls.
Player g_p1;
Level g_level;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void setup()
{
  g_gb.begin();
  //g_gb.titleScreen(logo);
  g_gb.battery.show = false;//hide the battery indicator
  g_gb.setFrameRate( g_fps );
  randomSeed(0);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void loop()
{
    if ( g_firstRun == true )
    {
        initalize();
        g_firstRun = false;
    }
    else if( g_gb.update() )
    {
        update();
    }
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void initalize()
{
    g_p1.pos.x = -10;
    g_p1.pos.y = 45;

    // Reset the level after the seed has been set
    g_level = Level();
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void update()
{
    logic();
    draw();
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void logic()
{
    move( g_p1 );  
    moveClouds( g_level );
    if ( g_p1.startLevel == true )
    {
        moveSeperators( g_level );
    }
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void draw()
{
    draw( g_level );
    draw( g_p1 );
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//imports the SPI library (needed to communicate with Gamebuino's screen)
#include <SPI.h>
//importe the Gamebuino library
#include <Gamebuino.h>

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//creates a Gamebuino object named g_gb
Gamebuino g_gb = Gamebuino();
//declare all the sprites which are in the "sprites" tab
//extern const byte PROGMEM logo[];

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Game variables.

// State.
bool g_firstRun = true;

// Character controls.
int g_startX = 10;
int g_startY = 10;
const short g_width = 1;
const short g_height = 1;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void setup()
{
  g_gb.begin();
  g_gb.pickRandomSeed();
  //g_gb.titleScreen(logo);
  g_gb.battery.show = false;//hide the battery indicator
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
    if (g_gb.buttons.repeat(BTN_UP, 1))
    {
        g_startY -= 1;
    }
    else if (g_gb.buttons.repeat(BTN_RIGHT, 1))
    {
        g_startX += 1;
    }
    else if (g_gb.buttons.repeat(BTN_DOWN, 1))
    {
        g_startY += 1;
    }
    else if (g_gb.buttons.repeat(BTN_LEFT, 1))
    {
        g_startX -= 1;
    }
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void draw()
{
    g_gb.display.fillRect(g_startX, g_startY, g_width, g_height);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

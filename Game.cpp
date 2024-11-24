
//--------------------------------------------------

#include "Engine.h"
#include <stdlib.h>
#include <memory.h>
#include <iostream>

#include "src/GameMaster/GameMaster.h"

//--------------------------------------------------

GameMaster* game_master = nullptr;
Screen*     screen      = nullptr;

void initialize()
{
    screen      = new Screen (buffer);
    game_master = new GameMaster (*screen);
    game_master->initialize ();
}

void act(float dt)
{
  if (is_key_pressed(VK_ESCAPE))
    schedule_quit_game();

    //--------------------------------------------------

    game_master->act ((double) dt);
}

void draw()
{
    memset(buffer, 0, SCREEN_HEIGHT * SCREEN_WIDTH * sizeof(uint32_t));
    game_master->draw ();
}

void finalize()
{
    delete game_master;
    delete screen;
}

//--------------------------------------------------

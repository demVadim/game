#include "Game.h"

int main()
{
    Game *game = new Game();
    
    game->runing();

    delete game;

    return 0;
}
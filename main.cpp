#include "Game.h"
#include "GSMainMenu.h"

int main()
{
    Game game;

    game.pushState(new GSMainMenu(&game));

    game.gameLoop();

    return EXIT_SUCCESS;
}
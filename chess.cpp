#include <iostream>

#include "Game.h"

int main(int argc, char* argv[])
{
  Game *game = new Game();

  game->run();

  return EXIT_SUCCESS;
}

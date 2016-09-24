#include <iostream>

#include "Game.h"

int main(int argc, char* argv[])
{
  Game *game = new Game();

  game->printBoard();

  return EXIT_SUCCESS;
}

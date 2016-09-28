#include <iostream>

#include "Game.h"

int main(int argc, char* argv[])
{
  if(argc > 1)
  {
    std::cout << argv[1] << std::endl;
  }

  Game *game = new Game();

  game->run();

  return EXIT_SUCCESS;
}

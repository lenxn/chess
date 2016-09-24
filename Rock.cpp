#include "Rock.h"
#include "Game.h"

Rock::Rock(const bool is_white)
{
  if(!is_white)
  {
  	is_white_ = false;
  }
  symbol_ = Game::ROCK;
}
#include "Queen.h"
#include "Game.h"

Queen::Queen(const bool is_white)
{
  if(!is_white)
  {
  	is_white_ = false;
  }
  symbol_ = Game::QUEEN;
}
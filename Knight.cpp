#include "Knight.h"
#include "Game.h"

Knight::Knight(const bool is_white)
{
  if(!is_white)
  {
  	is_white_ = false;
  }
  symbol_ = Game::KNIGHT;
}
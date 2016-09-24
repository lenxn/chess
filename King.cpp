#include "King.h"
#include "Game.h"

King::King(const bool is_white)
{
  if(!is_white)
  {
  	is_white_ = false;
  }
  symbol_ = Game::KING;
}
#include "Bishop.h"
#include "Game.h"

Bishop::Bishop(const bool is_white)
{
  if(!is_white)
  {
  	is_white_ = false;
  }
  symbol_ = Game::BISHOP;
}
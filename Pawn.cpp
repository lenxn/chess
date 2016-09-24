#include "Game.h"
#include "Pawn.h"

Pawn::Pawn(const bool is_white)
{
  if(!is_white)
  {
  	is_white_ = false;
  }
  symbol_ = Game::PAWN;
}
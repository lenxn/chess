#include "Game.h"
#include "Pawn.h"

Pawn::Pawn(const bool is_white)
{
  if(!is_white)
  {
  	is_white_ = false;
  }
  symbol_ = Game::PAWN;
  initial_position_ = true;
}

void Pawn::getAccessibleFields(
  Position initial_position,
  Field board[BOARD_DIMENSIONS][BOARD_DIMENSIONS], 
  bool access_map[BOARD_DIMENSIONS][BOARD_DIMENSIONS])
{
}

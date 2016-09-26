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

void Bishop::getAccessibleFields(
  Position initial_position,
  Field board[BOARD_DIMENSIONS][BOARD_DIMENSIONS], 
  bool access_map[BOARD_DIMENSIONS][BOARD_DIMENSIONS])
{
}
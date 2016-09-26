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

void Knight::getAccessibleFields(
  Position initial_position,
  Field board[BOARD_DIMENSIONS][BOARD_DIMENSIONS], 
  bool access_map[BOARD_DIMENSIONS][BOARD_DIMENSIONS])
{
}

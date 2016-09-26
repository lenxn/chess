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

void Queen::getAccessibleFields(
  Position initial_position,
  Field board[BOARD_DIMENSIONS][BOARD_DIMENSIONS], 
  bool access_map[BOARD_DIMENSIONS][BOARD_DIMENSIONS])
{
}

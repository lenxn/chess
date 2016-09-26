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

void Rock::getAccessibleFields(
  Position initial_position,
  Field board[BOARD_DIMENSIONS][BOARD_DIMENSIONS], 
  bool access_map[BOARD_DIMENSIONS][BOARD_DIMENSIONS])
{
  getStraightAccessibleFields(initial_position, board, access_map);
}

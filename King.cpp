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

void King::getAccessibleFields(
  Position initial_position,
  Field board[BOARD_DIMENSIONS][BOARD_DIMENSIONS], 
  bool access_map[BOARD_DIMENSIONS][BOARD_DIMENSIONS])
{
}
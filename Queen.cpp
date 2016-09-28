#include "Queen.h"
#include "Game.h"

//------------------------------------------------------------------------------
const std::string Queen::UTF_SYMBOL = "\u2655";

//------------------------------------------------------------------------------
void Queen::getAccessibleFields(
  Position initial_position,
  Field board[BOARD_DIMENSIONS][BOARD_DIMENSIONS], 
  bool access_map[BOARD_DIMENSIONS][BOARD_DIMENSIONS])
{
  getStraightAccessibleFields(initial_position, board, access_map);
  getDiagonalAccessibleFields(initial_position, board, access_map);
}

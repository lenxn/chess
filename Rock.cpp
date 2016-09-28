#include "Rock.h"
#include "Game.h"

//------------------------------------------------------------------------------
const std::string Rock::UTF_SYMBOL = "\u2656";

//------------------------------------------------------------------------------
void Rock::getAccessibleFields(
  Position initial_position,
  Field board[BOARD_DIMENSIONS][BOARD_DIMENSIONS], 
  bool access_map[BOARD_DIMENSIONS][BOARD_DIMENSIONS])
{
  getStraightAccessibleFields(initial_position, board, access_map);
}

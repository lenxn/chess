#include "King.h"
#include "Game.h"

//------------------------------------------------------------------------------
const std::string King::UTF_SYMBOL = "\u2654";

//------------------------------------------------------------------------------
void King::getAccessibleFields(
  Position initial_position,
  Field board[BOARD_DIMENSIONS][BOARD_DIMENSIONS], 
  bool access_map[BOARD_DIMENSIONS][BOARD_DIMENSIONS])
{
  getStraightAccessibleFields(initial_position, board, access_map, MAX_MOVEMENT_DISTANCE);
  getDiagonalAccessibleFields(initial_position, board, access_map, MAX_MOVEMENT_DISTANCE);
}


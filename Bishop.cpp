#include "Bishop.h"

//------------------------------------------------------------------------------
const std::string Bishop::UTF_SYMBOL = "\u2657";

//------------------------------------------------------------------------------
void Bishop::getAccessibleFields(
  Position initial_position,
  Field board[BOARD_DIMENSIONS][BOARD_DIMENSIONS], 
  bool access_map[BOARD_DIMENSIONS][BOARD_DIMENSIONS])
{
  getDiagonalAccessibleFields(initial_position, board, access_map);
}
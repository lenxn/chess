#include "Knight.h"

//------------------------------------------------------------------------------
const std::string Knight::UTF_SYMBOL = "\u2658";

//------------------------------------------------------------------------------
void Knight::getAccessibleFields(
  Position initial_position,
  Field board[BOARD_DIMENSIONS][BOARD_DIMENSIONS], 
  bool access_map[BOARD_DIMENSIONS][BOARD_DIMENSIONS])
{
  int src_row = initial_position.row;
  int src_col = initial_position.col;
  int dest_row;
  int dest_col;
  bool player_is_white = board[src_row][src_col].getPiece()->isWhite();

  // 8 possible positions (clockwise)
  // move up-right
  dest_row = src_row - LONG_HOP_DISTANCE;
  dest_col = src_col + SHORT_HOP_DISTANCE;
  if(dest_row >= 0 && dest_col <= BOARD_DIMENSIONS)
  {
    if(board[dest_row][dest_col].isAccessible(player_is_white))
    {
      access_map[dest_row][dest_col] = true;
    }
  }

  // move right-up
  dest_row = src_row - SHORT_HOP_DISTANCE;
  dest_col = src_col + LONG_HOP_DISTANCE;
  if(dest_row >= 0 && dest_col <= BOARD_DIMENSIONS)
  {
    if(board[dest_row][dest_col].isAccessible(player_is_white))
    {
      access_map[dest_row][dest_col] = true;
    }
  }

  // move right-down
  dest_row = src_row + SHORT_HOP_DISTANCE;
  dest_col = src_col + LONG_HOP_DISTANCE;
  if(dest_row <= BOARD_DIMENSIONS && dest_col <= BOARD_DIMENSIONS)
  {
    if(board[dest_row][dest_col].isAccessible(player_is_white))
    {
      access_map[dest_row][dest_col] = true;
    }
  }

  // move down-right
  dest_row = src_row + LONG_HOP_DISTANCE;
  dest_col = src_col + SHORT_HOP_DISTANCE;
  if(dest_row <= BOARD_DIMENSIONS && dest_col <= BOARD_DIMENSIONS)
  {
    if(board[dest_row][dest_col].isAccessible(player_is_white))
    {
      access_map[dest_row][dest_col] = true;
    }
  }

  // move down-left
  dest_row = src_row + LONG_HOP_DISTANCE;
  dest_col = src_col - SHORT_HOP_DISTANCE;
  if(dest_row <= BOARD_DIMENSIONS && dest_col >= 0)
  {
    if(board[dest_row][dest_col].isAccessible(player_is_white))
    {
      access_map[dest_row][dest_col] = true;
    }
  }

  // move left-down
  dest_row = src_row + SHORT_HOP_DISTANCE;
  dest_col = src_col - LONG_HOP_DISTANCE;
  if(dest_row <= BOARD_DIMENSIONS && dest_col >= 0)
  {
    if(board[dest_row][dest_col].isAccessible(player_is_white))
    {
      access_map[dest_row][dest_col] = true;
    }
  }

  // move left-up
  dest_row = src_row - SHORT_HOP_DISTANCE;
  dest_col = src_col - LONG_HOP_DISTANCE;
  if(dest_row >= 0 && dest_col >= 0)
  {
    if(board[dest_row][dest_col].isAccessible(player_is_white))
    {
      access_map[dest_row][dest_col] = true;
    }
  }

  // move up-left
  dest_row = src_row - LONG_HOP_DISTANCE;
  dest_col = src_col - SHORT_HOP_DISTANCE;
  if(dest_row >= 0 && dest_col >= 0)
  {
    if(board[dest_row][dest_col].isAccessible(player_is_white))
    {
      access_map[dest_row][dest_col] = true;
    }
  }
}

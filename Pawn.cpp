#include "Game.h"
#include "Pawn.h"

//------------------------------------------------------------------------------
const std::string Pawn::UTF_SYMBOL = "\u2659";

//------------------------------------------------------------------------------
void Pawn::getAccessibleFields(
  Position initial_position,
  Field board[BOARD_DIMENSIONS][BOARD_DIMENSIONS], 
  bool access_map[BOARD_DIMENSIONS][BOARD_DIMENSIONS])
{
  bool player_is_white = board[initial_position.row][initial_position.col].getPiece()->isWhite();

  if(player_is_white && initial_position.row != 0)
  {
    access_map[initial_position.row - MOVEMENT_DISTANCE][initial_position.col] = true;

    if(board[initial_position.row - MOVEMENT_DISTANCE][initial_position.col - MOVEMENT_DISTANCE].isAccessible(player_is_white)
      && board[initial_position.row - MOVEMENT_DISTANCE][initial_position.col - MOVEMENT_DISTANCE].isOccupied())
    {
      access_map[initial_position.row - MOVEMENT_DISTANCE][initial_position.col - MOVEMENT_DISTANCE] = true;
    }
    if(board[initial_position.row - MOVEMENT_DISTANCE][initial_position.col + MOVEMENT_DISTANCE].isAccessible(player_is_white)
      && board[initial_position.row - MOVEMENT_DISTANCE][initial_position.col + MOVEMENT_DISTANCE].isOccupied())
    {
      access_map[initial_position.row - MOVEMENT_DISTANCE][initial_position.col + MOVEMENT_DISTANCE] = true;
    }

    if(initial_position_)
    {
      access_map[initial_position.row - INITIAL_MOVEMENT_DISTANCE][initial_position.col] = true;
    }
  }

  if(!player_is_white && initial_position.row != BOARD_DIMENSIONS)
  {
    access_map[initial_position.row + MOVEMENT_DISTANCE][initial_position.col] = true;

    if(board[initial_position.row + MOVEMENT_DISTANCE][initial_position.col - MOVEMENT_DISTANCE].isAccessible(player_is_white)
      && board[initial_position.row + MOVEMENT_DISTANCE][initial_position.col - MOVEMENT_DISTANCE].isOccupied())
    {
      access_map[initial_position.row + MOVEMENT_DISTANCE][initial_position.col - MOVEMENT_DISTANCE] = true;
    }
    if(board[initial_position.row + MOVEMENT_DISTANCE][initial_position.col + MOVEMENT_DISTANCE].isAccessible(player_is_white)
      && board[initial_position.row + MOVEMENT_DISTANCE][initial_position.col + MOVEMENT_DISTANCE].isOccupied())
    {
      access_map[initial_position.row + MOVEMENT_DISTANCE][initial_position.col + MOVEMENT_DISTANCE] = true;
    }

    if(initial_position_)
    {
      access_map[initial_position.row + INITIAL_MOVEMENT_DISTANCE][initial_position.col] = true;
    }
  }
}

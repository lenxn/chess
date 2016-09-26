#include "Piece.h"
#include "Field.h"

#include <iostream>

//------------------------------------------------------------------------------
Piece::Piece()
{
  is_white_ = true;
}

//------------------------------------------------------------------------------
void Piece::getStraightAccessibleFields(
  Position initial_position, 
  Field board[BOARD_DIMENSIONS][BOARD_DIMENSIONS],
  bool access_map[BOARD_DIMENSIONS][BOARD_DIMENSIONS],
  unsigned int max_distance
)
{
  int row = initial_position.row;
  int col = initial_position.col;
  bool player_is_white = board[row][col].getPiece()->isWhite();

  // check upwards
  if(row != 0)
  {
    row--;
    while(row >= 0 && board[row][col].isAccessible(player_is_white))
    {
      access_map[row][col] = true;
      if(board[row][col].isOccupied())
      {
        break;
      }
      row--;
    }
  }

  // check to right
  row = initial_position.row;
  col = initial_position.col;
  if(col != BOARD_DIMENSIONS)
  {
    col++;
    while(col < BOARD_DIMENSIONS && board[row][col].isAccessible(player_is_white))
    {
      access_map[row][col] = true;
      if(board[row][col].isOccupied())
      {
        break;
      }
      col++;
    }
  }

  // check downwards
  row = initial_position.row;
  col = initial_position.col;
  if(row != BOARD_DIMENSIONS)
  {
    row++;
    while(row <= BOARD_DIMENSIONS && board[row][col].isAccessible(player_is_white))
    {
      access_map[row][col] = true;
      if(board[row][col].isOccupied())
      {
        break;
      }
      row++;
    }
  }

  // check to left
  row = initial_position.row;
  col = initial_position.col;
  if(col != 0)
  {
    col--;
    while(col >= 0 && board[row][col].isAccessible(player_is_white))
    {
      access_map[row][col] = true;
      if(board[row][col].isOccupied())
      {
        break;
      }
      col--;
    }
  }
}

//------------------------------------------------------------------------------
void Piece::getDiagonalAccessibleFields(
  Position initial_position, 
  Field board[BOARD_DIMENSIONS][BOARD_DIMENSIONS],
  bool access_map[BOARD_DIMENSIONS][BOARD_DIMENSIONS],
  unsigned int max_distance
)
{
}

//------------------------------------------------------------------------------
const bool Piece::isWhite()
{
  return is_white_;
}

//------------------------------------------------------------------------------
const char Piece::getSymbol()
{
  return symbol_;
}

//------------------------------------------------------------------------------
const bool Piece::moveIsPossible(Field board[BOARD_DIMENSIONS][BOARD_DIMENSIONS], Position src, Position dest)
{
  bool access_map[BOARD_DIMENSIONS][BOARD_DIMENSIONS];
  for(unsigned int row = 0; row < BOARD_DIMENSIONS; row++)
  {
    for(unsigned int col = 0; col < BOARD_DIMENSIONS; col++)
    {
      access_map[row][col] = false;
    }
  }

  getAccessibleFields(src, board, access_map);

  
  for(unsigned int row = 0; row < BOARD_DIMENSIONS; row++)
  {
    for(unsigned int col = 0; col < BOARD_DIMENSIONS; col++)
    {
      std::cout << access_map[row][col];
    }
    std::cout << std::endl;
  }  

  return access_map[dest.row][dest.col];
}
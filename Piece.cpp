#include "Piece.h"
#include "Field.h"
#include "Config.h"
#include "Game.h"

#include "King.h"
#include "Queen.h"
#include "Rock.h"
#include "Bishop.h"
#include "Knight.h"
#include "Pawn.h"

#include <iostream>

//------------------------------------------------------------------------------
Piece::Piece()
{
  is_white_ = true;
}

//------------------------------------------------------------------------------
Piece::Piece(const bool is_white, const char type)
{
  initial_position_ = true;

  if(!is_white)
  {
    is_white_ = false;
  }
  else
  {
    is_white_ = true;
  }

  if(Config::useUtfSymbols())
  {
    switch(type)
    {
      case Game::KING:
        symbol_ = King::UTF_SYMBOL;
        break;
      case Game::QUEEN:
        symbol_ = Queen::UTF_SYMBOL;
        break;
      case Game::ROCK:
        symbol_ = Rock::UTF_SYMBOL;
        break;
      case Game::BISHOP:
        symbol_ = Bishop::UTF_SYMBOL;
        break;
      case Game::KNIGHT:
        symbol_ = Knight::UTF_SYMBOL;
        break;
      case Game::PAWN:
        symbol_ = Pawn::UTF_SYMBOL;
    }
  }
  else
  {
    symbol_ = Game::KING;
  }
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
  unsigned int remaining_steps = max_distance;
  bool player_is_white = board[row][col].getPiece()->isWhite();

  // check upwards
  if(row != 0)
  {
    row--;
    while(row >= 0 && board[row][col].isAccessible(player_is_white)
      && remaining_steps > 0)
    {
      access_map[row][col] = true;
      if(board[row][col].isOccupied())
      {
        break;
      }
      remaining_steps--;
      row--;
    }
  }

  // check to right
  row = initial_position.row;
  col = initial_position.col;
  remaining_steps = max_distance;
  if(col != BOARD_DIMENSIONS)
  {
    col++;
    while(col < BOARD_DIMENSIONS 
      && board[row][col].isAccessible(player_is_white)
      && remaining_steps > 0)
    {
      access_map[row][col] = true;
      if(board[row][col].isOccupied())
      {
        break;
      }
      remaining_steps--;
      col++;
    }
  }

  // check downwards
  row = initial_position.row;
  col = initial_position.col;
  remaining_steps = max_distance;
  if(row != BOARD_DIMENSIONS)
  {
    row++;
    while(row <= BOARD_DIMENSIONS 
      && board[row][col].isAccessible(player_is_white)
      && remaining_steps > 0)
    {
      access_map[row][col] = true;
      if(board[row][col].isOccupied())
      {
        break;
      }
      remaining_steps--;
      row++;
    }
  }

  // check to left
  row = initial_position.row;
  col = initial_position.col;
  remaining_steps = max_distance;
  if(col != 0)
  {
    col--;
    while(col >= 0 && board[row][col].isAccessible(player_is_white)
      && remaining_steps > 0)
    {
      access_map[row][col] = true;
      if(board[row][col].isOccupied())
      {
        break;
      }
      remaining_steps--;
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
  int row = initial_position.row;
  int col = initial_position.col;
  unsigned int remaining_steps = max_distance;
  bool player_is_white = board[row][col].getPiece()->isWhite();

  // check to up-right
  if(row != 0 && col != (BOARD_DIMENSIONS -1))
  {
    row--;
    col++;
    while(row >= 0 && col <= (BOARD_DIMENSIONS - 1)
      && board[row][col].isAccessible(player_is_white)
      && remaining_steps > 0)
    {
      access_map[row][col] = true;
      if(board[row][col].isOccupied())
      {
        break;
      }

      std::cout << "row " << row << std::endl;
      std::cout << "col " << col << std::endl;
      remaining_steps--;
      row--;
      col++;
    }
  }

  // check to down-right
  row = initial_position.row;
  col = initial_position.col;
  remaining_steps = max_distance;
  if(row != (BOARD_DIMENSIONS - 1) && col != (BOARD_DIMENSIONS - 1))
  {
    row++;
    col++;
    while(row <= (BOARD_DIMENSIONS - 1) && col <= (BOARD_DIMENSIONS - 1)
      && board[row][col].isAccessible(player_is_white)
      && remaining_steps > 0)
    {
      access_map[row][col] = true;
      if(board[row][col].isOccupied())
      {
        break;
      }
      remaining_steps--;
      row++;
      col++;
    }
  }

  // check to down-left
  row = initial_position.row;
  col = initial_position.col;
  remaining_steps = max_distance;
  if(row != (BOARD_DIMENSIONS - 1) && col != 0)
  {
    row++;
    col--;
    while(row <= (BOARD_DIMENSIONS - 1) && col >= 0 
      && board[row][col].isAccessible(player_is_white)
      && remaining_steps > 0)
    {
      access_map[row][col] = true;
      if(board[row][col].isOccupied())
      {
        break;
      }
      remaining_steps--;
      row++;
      col--;
    }
  }

  // check to up-left
  row = initial_position.row;
  col = initial_position.col;
  remaining_steps = max_distance;
  if(row != 0 && col != 0)
  {
    row--;
    col--;
    while(row >= 0 && col >= 0 
      && board[row][col].isAccessible(player_is_white)
      && remaining_steps > 0)
    {
      access_map[row][col] = true;
      if(board[row][col].isOccupied())
      {
        break;
      }
      remaining_steps--;
      row--;
      col--;
    }
  }
}

//------------------------------------------------------------------------------
const bool Piece::isWhite()
{
  return is_white_;
}

//------------------------------------------------------------------------------
const std::string Piece::getSymbol()
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
  return access_map[dest.row][dest.col];
}

//------------------------------------------------------------------------------
void Piece::markAsMoved()
{
  initial_position_ = false;
}
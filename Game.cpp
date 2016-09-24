#include <iostream>

#include "Game.h"
#include "Field.h"

const char* Game::START_BLACK_CMD_COLOR = "\e[0;35m";
const char* Game::END_BLACK_CMD_COLOR = "\e[m";

Game::Game()
{
  initBoard();
}

const void Game::run()
{
    
}

const void Game::initBoard()
{
  for(unsigned int row = 0; row < BOARD_DIMENSIONS; row++)
  {
    for(unsigned int col = 0; col < BOARD_DIMENSIONS; col++)
    {
      if(row == 0)
      {
        if(col == 0 || col == 7)
        {
          board_[row][col].initPiece(ROCK, false);
        }
        if(col == 1 || col == 6)
        {
          board_[row][col].initPiece(KNIGHT, false);
        }
        if(col == 2 || col == 5)
        {
          board_[row][col].initPiece(BISHOP, false);
        }
        if(col == 3)
        {
          board_[row][col].initPiece(QUEEN, false);
        }
        if(col == 4)
        {
          board_[row][col].initPiece(KING, false);
        }
      }
      if(row == 1)
      {
        board_[row][col].initPiece(PAWN, false);
      }
      if(row == 6)
      {
        board_[row][col].initPiece(PAWN, true);
      }
      if(row == 7)
      {
        if(col == 0 || col == 7)
        {
          board_[row][col].initPiece(ROCK, true);
        }
        if(col == 1 || col == 6)
        {
          board_[row][col].initPiece(KNIGHT, true);
        }
        if(col == 2 || col == 5)
        {
          board_[row][col].initPiece(BISHOP, true);
        }
        if(col == 3)
        {
          board_[row][col].initPiece(QUEEN, true);
        }
        if(col == 4)
        {
          board_[row][col].initPiece(KING, true);
        }
      }
    }
  }
}

const void Game::printBoard()
{
  unsigned int index = BOARD_DIMENSIONS;

  std::cout << "     a   b   c   d   e   f   g   h  " << std::endl;
  std::cout << "   +---+---+---+---+---+---+---+---+" << std::endl;
  for(unsigned int row = 0; row < BOARD_DIMENSIONS; row++, index--)
  {
    std::cout << ' ' << index << ' ' << FIELD_DELIMITER << ' ';
    for(unsigned int col = 0; col < BOARD_DIMENSIONS; col++)
    {
      if(board_[row][col].isOccupied())
      {
        if(board_[row][col].getPiece()->isWhite())
        {
          std::cout << board_[row][col].getPiece()->getSymbol();
        }
        else
        {
          std::cout << START_BLACK_CMD_COLOR << board_[row][col].getPiece()->getSymbol() << END_BLACK_CMD_COLOR;
        }
      }
      else
      {
        std::cout << EMPTY_FIELD;
      }
      std::cout << ' ' << FIELD_DELIMITER << ' ';
    }
    std::cout << ' ' << index << std::endl;
    std::cout << "   +---+---+---+---+---+---+---+---+" << std::endl;
  } 
  std::cout << "     a   b   c   d   e   f   g   h  " << std::endl;
}


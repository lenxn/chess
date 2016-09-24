#include <iostream>

#include "Game.h"
#include "Field.h"

const char* Game::START_BLACK_CMD_COLOR = "\e[0;35m";
const char* Game::END_BLACK_CMD_COLOR = "\e[m";

Game::Game()
{
  initBoard();
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
  std::cout << "+---+---+---+---+---+---+---+---+" << std::endl;
  for(unsigned int col = 0; col < BOARD_DIMENSIONS; col++)
  {
    std::cout << FIELD_DELIMITER << ' ';
    for(unsigned int row = 0; row < BOARD_DIMENSIONS; row++)
    {
      if(board_[col][row].isOccupied())
      {
        if(board_[col][row].getPiece()->isWhite())
        {
          std::cout << board_[col][row].getPiece()->getSymbol();
        }
        else
        {
          std::cout << START_BLACK_CMD_COLOR << board_[col][row].getPiece()->getSymbol() << END_BLACK_CMD_COLOR;
        }
      }
      else
      {
        std::cout << EMPTY_FIELD;
      }
      std::cout << ' ' << FIELD_DELIMITER << ' ';
    }
    std::cout << std::endl << "+---+---+---+---+---+---+---+---+" << std::endl;
  } 
}


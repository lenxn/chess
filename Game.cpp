#include <iostream>
#include <string>
#include <regex>

#include "Game.h"
#include "NoPieceException.h"
#include "WrongPlayerException.h"
#include "CannotTakeOwnPieceException.h"
#include "InvalidMoveException.h"

const char* Game::EXIT_COMMAND = "exit";
const char* Game::MOVEMENT_REGEX = ".?([a-h][1-8])-([a-h][1-8])";

const char* Game::START_WHITE_CMD_COLOR = "\e[0;36m";
const char* Game::START_BLACK_CMD_COLOR = "\e[0;35m";
const char* Game::END_WHITE_CMD_COLOR = "\e[m";
const char* Game::END_BLACK_CMD_COLOR = "\e[m";

Game::Game()
{
  initBoard();
  checkmate_ = false;
  white_in_charge_ = true;
}

const void Game::run()
{
  Position src;
  Position dest;
  std::string command;
  std::smatch match;
  std::regex rgx(MOVEMENT_REGEX);
    

  std::cout << "Starting new Game." << std::endl;
  while(!checkmate_)
  {
    printBoard();
    if(white_in_charge_)
    {
      std::cout << "Next move by " << START_WHITE_CMD_COLOR << "White" << END_WHITE_CMD_COLOR << ": ";
    }
    else
    {
      std::cout << "Next move by " << START_BLACK_CMD_COLOR << "Black" << END_BLACK_CMD_COLOR << ": ";
    }
    std::cin >> command;

    if(command == EXIT_COMMAND)
    {
      return;
    }
    
    if(std::regex_search(command, match, rgx))
    {
      src.row = -1 * (int(match.str(1)[1] - '1') + 1) + BOARD_DIMENSIONS;
      src.col = match.str(1)[0] - 'a';
      dest.row = -1 * (int(match.str(2)[1] - '1') + 1) + BOARD_DIMENSIONS;
      dest.col = match.str(2)[0] - 'a';

      try
      {
        movePiece(src, dest);
        if(isCheckmate())
        {
          checkmate_ = true;
          if(white_in_charge_)
          {
            std::cout << "White Player wins." << std::endl << "Gratulation!" << std::endl;
          }
          else
          {
            std::cout << "Black Player wins." << std::endl << "Gratulation!" << std::endl; 
          }
        }

        if(white_in_charge_)
        {
          white_in_charge_ = false;
        }
        else
        {
          white_in_charge_ = true;
        }
      }
      catch(NoPieceException)
      {
        std::cout << "No piece found at source position." << std::endl;
      }
      catch(WrongPlayerException)
      {
        std::cout << "The piece at source position does not belong to the current Player." << std::endl;
      }
      catch(CannotTakeOwnPieceException)
      {
        std::cout << "The piece at the destination field belongs to the current Player." << std::endl;
      }
      catch(InvalidMoveException)
      {
        std::cout << "Invalid Move for this piece" << std::endl;
      }
    }
    else
    {
      std::cout << "Invalid Move!" << std::endl;
    }
  }
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
          std::cout << START_WHITE_CMD_COLOR << board_[row][col].getPiece()->getSymbol() << END_WHITE_CMD_COLOR;
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

const void Game::movePiece(Position src, Position dest)
{
  Field *src_field = &board_[src.row][src.col];
  Field *dest_field = &board_[dest.row][dest.col];

  if(src_field->isOccupied())
  {
    if((src_field->getPiece()->isWhite() && white_in_charge_) 
      || (!src_field->getPiece()->isWhite() && !white_in_charge_))
    {
      if(!dest_field->isOccupied()
        || (dest_field->getPiece()->isWhite() && !white_in_charge_) 
        || (!dest_field->getPiece()->isWhite() && white_in_charge_))
      {
        if(src_field->getPiece()->moveIsPossible(board_, src, dest))
        {
          dest_field->setPiece(src_field->getPiece());
          dest_field->getPiece()->markAsMoved();
          src_field->setPiece(0);
        }
        else
        {
          throw InvalidMoveException();
        }
      }
      else
      {
        throw CannotTakeOwnPieceException();
      }
    }
    else
    {
      throw WrongPlayerException(); 
    }
  }
  else
  {
    throw NoPieceException();
  }
}

const bool Game::isCheckmate()
{
  return false;
}


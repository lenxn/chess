#include <iostream>
#include <vector>

#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "Field.h"

class Game
{
  public:
    //--------------------------------------------------------------------------
    // constant
    //
    static const int BOARD_DIMENSIONS = 8;
    static const char FIELD_DELIMITER = '|';
    static const char EMPTY_FIELD = ' ';

    static const char* EXIT_COMMAND;
    static const char* MOVEMENT_REGEX;

    static const char* START_WHITE_CMD_COLOR;
    static const char* START_BLACK_CMD_COLOR;
    static const char* END_WHITE_CMD_COLOR;
    static const char* END_BLACK_CMD_COLOR;

    enum Pieces
    {
      KING = 'K',
      QUEEN = 'Q',
      ROCK = 'R',
      BISHOP = 'B',
      KNIGHT = 'N',
      PAWN = 'P'
    };

  private:
    bool checkmate_;
    bool white_in_charge_;
    std::vector<std::string> history_;
    Field board_[BOARD_DIMENSIONS][BOARD_DIMENSIONS];

    const void initBoard();
    const void movePiece(Position, Position);
    const bool isCheckmate();

  public:

    Game();
    const void run();
    const void printBoard();

};

#endif
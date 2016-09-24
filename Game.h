#include <iostream>

#include "Field.h"

#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

class Game
{
  public:
    //--------------------------------------------------------------------------
    // constant
    //
    static const int BOARD_DIMENSIONS = 8;
    static const char FIELD_DELIMITER = '|';
    static const char EMPTY_FIELD = ' ';

    static const char* START_BLACK_CMD_COLOR;
    static const char* END_BLACK_CMD_COLOR;


  private:
    Field board_[BOARD_DIMENSIONS][BOARD_DIMENSIONS];

    const void initBoard();

  public:

    enum Pieces
    {
      KING = 'K',
      QUEEN = 'Q',
      ROCK = 'R',
      BISHOP = 'B',
      KNIGHT = 'N',
      PAWN = 'P'
    };
    Game();

    const void printBoard();

};

#endif
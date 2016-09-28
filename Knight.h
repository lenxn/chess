#ifndef KNIGHT_H_INCLUDED
#define KNIGHT_H_INCLUDED

#include "Piece.h"
#include "Game.h"

class Knight : public Piece
{
  private:
    //--------------------------------------------------------------------------
    // Constants.
    //
    static const unsigned int LONG_HOP_DISTANCE = 2;
    static const unsigned int SHORT_HOP_DISTANCE = 1;

    //--------------------------------------------------------------------------
    // Get Accessible Fields.
    //
    virtual void getAccessibleFields(
      Position, 
      Field[BOARD_DIMENSIONS][BOARD_DIMENSIONS],
      bool[BOARD_DIMENSIONS][BOARD_DIMENSIONS]
    );
  
  public:
    //--------------------------------------------------------------------------
    // Constants.
    //
    static const std::string UTF_SYMBOL;

    //--------------------------------------------------------------------------
    // Constructor.
    //
    Knight(const bool is_white) : Piece(is_white, Game::KNIGHT) {}
};

#endif
#ifndef KING_H_INCLUDED
#define KING_H_INCLUDED

#include "Piece.h"
#include "Game.h"

class King : public Piece
{
  private:
    //--------------------------------------------------------------------------
    // Constants.
    //
    static const unsigned int MAX_MOVEMENT_DISTANCE = 1;

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
    King(const bool is_white) : Piece(is_white, Game::KING) {}
};

#endif
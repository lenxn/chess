#ifndef PAWN_H_INCLUDED
#define PAWN_H_INCLUDED

#include "Piece.h"
#include "Game.h"

class Pawn : public Piece
{
  private:
    //--------------------------------------------------------------------------
    // Constants.
    //
    static const unsigned int MOVEMENT_DISTANCE = 1;
    static const unsigned int INITIAL_MOVEMENT_DISTANCE = 2;

    //--------------------------------------------------------------------------
    // Get Accessible Fields.
    //
    // todo:
    // - piece reaches other side of the board
    // - piece gets overtaken by enemy pawn
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
    Pawn(const bool is_white) : Piece(is_white, Game::PAWN) {}
};

#endif
#ifndef QUEEN_H_INCLUDED
#define QUEEN_H_INCLUDED

#include "Piece.h"
#include "Game.h"

class Queen : public Piece
{
  private:
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
    Queen(const bool is_white) : Piece(is_white, Game::QUEEN) {}
};

#endif
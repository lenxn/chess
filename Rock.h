#ifndef ROCK_H_INCLUDED
#define ROCK_H_INCLUDED

#include "Piece.h"
#include "Game.h"

class Rock : public Piece
{
  private:
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
    Rock(const bool is_white) : Piece(is_white, Game::ROCK) {}
};

#endif
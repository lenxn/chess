#ifndef PAWN_H_INCLUDED
#define PAWN_H_INCLUDED

#include "Piece.h"

class Pawn : public Piece
{
  private:
  	bool initial_position_;
    virtual void getAccessibleFields(
      Position, 
      Field[BOARD_DIMENSIONS][BOARD_DIMENSIONS],
      bool[BOARD_DIMENSIONS][BOARD_DIMENSIONS]
    );

  public:
    Pawn(const bool is_white);
};

#endif
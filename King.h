#ifndef KING_H_INCLUDED
#define KING_H_INCLUDED

#include "Piece.h"

class King : public Piece
{
  private:
    virtual void getAccessibleFields(
      Position, 
      Field[BOARD_DIMENSIONS][BOARD_DIMENSIONS],
      bool[BOARD_DIMENSIONS][BOARD_DIMENSIONS]
    );
   
  public:
    King(const bool is_white);
};

#endif
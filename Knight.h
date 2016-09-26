#ifndef KNIGHT_H_INCLUDED
#define KNIGHT_H_INCLUDED

#include "Piece.h"

class Knight : public Piece
{
  private:
    virtual void getAccessibleFields(
      Position, 
      Field[BOARD_DIMENSIONS][BOARD_DIMENSIONS],
      bool[BOARD_DIMENSIONS][BOARD_DIMENSIONS]
    );
  
  public:
    Knight(const bool is_white);
};

#endif
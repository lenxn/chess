#ifndef BISHOP_H_INCLUDED
#define BISHOP_H_INCLUDED

#include "Piece.h"

class Bishop : public Piece
{
  private:
    virtual void getAccessibleFields(
      Position, 
      Field[BOARD_DIMENSIONS][BOARD_DIMENSIONS],
      bool[BOARD_DIMENSIONS][BOARD_DIMENSIONS]
    );
    
  public:
    Bishop(const bool is_white);
};

#endif
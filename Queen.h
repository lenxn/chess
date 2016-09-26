#ifndef QUEEN_H_INCLUDED
#define QUEEN_H_INCLUDED

#include "Piece.h"

class Queen : public Piece
{
  private:
    virtual void getAccessibleFields(
      Position, 
      Field[BOARD_DIMENSIONS][BOARD_DIMENSIONS],
      bool[BOARD_DIMENSIONS][BOARD_DIMENSIONS]
    );
    
  public:
    Queen(const bool is_white);
};

#endif
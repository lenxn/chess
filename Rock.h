#ifndef ROCK_H_INCLUDED
#define ROCK_H_INCLUDED

#include "Piece.h"

class Rock : public Piece
{
  private:
    virtual void getAccessibleFields(
      Position, 
      Field[BOARD_DIMENSIONS][BOARD_DIMENSIONS],
      bool[BOARD_DIMENSIONS][BOARD_DIMENSIONS]
    );

  public:
    Rock(const bool is_white);
};

#endif
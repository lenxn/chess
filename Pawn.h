#ifndef PAWN_H_INCLUDED
#define PAWN_H_INCLUDED

#include "Piece.h"

class Pawn : public Piece
{
  public:
    Pawn(const bool is_white);
};

#endif
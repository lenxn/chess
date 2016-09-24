#ifndef QUEEN_H_INCLUDED
#define QUEEN_H_INCLUDED

#include "Piece.h"

class Queen : public Piece
{
  public:
    Queen(const bool is_white);
};

#endif
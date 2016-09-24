#ifndef ROCK_H_INCLUDED
#define ROCK_H_INCLUDED

#include "Piece.h"

class Rock : public Piece
{
  public:
    Rock(const bool is_white);
};

#endif
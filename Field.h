#include "Piece.h"

#ifndef FIELD_H_INCLUDED
#define FIELD_H_INCLUDED

class Field
{
  private:
    bool occupied_;
    Piece *piece_;

  public:
    Field();

    Piece* getPiece();
    const bool isOccupied();
    void initPiece(const char type, const bool is_white);
};

#endif
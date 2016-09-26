#ifndef FIELD_H_INCLUDED
#define FIELD_H_INCLUDED



#include "Piece.h"



class Field
{
  private:
    bool occupied_;
    Piece *piece_;

  public:
    Field();

    Piece* getPiece();
    const void setPiece(Piece*);
    const bool isOccupied();
    const bool isAccessible(const bool player_is_white);
    void initPiece(const char type, const bool is_white);
};

#endif
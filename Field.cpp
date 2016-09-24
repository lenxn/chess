
#include <iostream>

#include "Field.h"
#include "Game.h"
#include "King.h"
#include "Queen.h"
#include "Rock.h"
#include "Bishop.h"
#include "Knight.h"
#include "Pawn.h"

Field::Field()
{
  occupied_ = false;
  piece_ = 0;
}

const bool Field::isOccupied()
{
  return occupied_;
}

Piece* Field::getPiece()
{
  return piece_;
}

void Field::initPiece(const char type, const bool is_white)
{
  switch(type)
  {
    case Game::KING:
      piece_ = new King(is_white);
      break;
    case Game::QUEEN:
      piece_ = new Queen(is_white);
      break;
    case Game::ROCK:  
      piece_ = new Rock(is_white);
      break;
    case Game::BISHOP:
      piece_ = new Bishop(is_white);
      break;
    case Game::KNIGHT:
      piece_ = new Knight(is_white);
      break;
    case Game::PAWN:
      piece_ = new Pawn(is_white);
      break;
  }
  occupied_ = true;
}

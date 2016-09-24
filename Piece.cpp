#include "Piece.h"

Piece::Piece()
{
  is_white_ = true;
}

const bool Piece::isWhite()
{
  return is_white_;
}

const char Piece::getSymbol()
{
  return symbol_;
}
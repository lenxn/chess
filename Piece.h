#ifndef PIECE_H_INCLUDED
#define PIECE_H_INCLUDED

class Piece
{
  private:

  protected:
  	bool is_white_;
    char symbol_;

  public:

  	
    Piece();
    const bool isWhite();
    const char getSymbol();
};

#endif
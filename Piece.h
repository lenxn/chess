#ifndef PIECE_H_INCLUDED
#define PIECE_H_INCLUDED

#include <limits>

class Field;

struct Position
{
  unsigned int row;
  unsigned int col;
};

class Piece
{
  protected:
    //--------------------------------------------------------------------------
    // constant
    //
    static const int BOARD_DIMENSIONS = 8;

  	bool is_white_;
    char symbol_;

    //--------------------------------------------------------------------------
    // Get Straigt Accessible Fields.
    // Set all fields in access_map which are accessible from initial_position
    // in diagonal direction with a maximum of max_distance steps.
    //
    void getStraightAccessibleFields(
      Position initial_position, 
      Field board[BOARD_DIMENSIONS][BOARD_DIMENSIONS], 
      bool access_map[BOARD_DIMENSIONS][BOARD_DIMENSIONS],
      unsigned int max_distance = std::numeric_limits<unsigned int>::max()
    );

    //--------------------------------------------------------------------------
    // Get Diagonal AccessibleFields.
    // Set all fields in access_map which are accessible from initial_position
    // in diagonal direction with a maximum of max_distance steps.
    //
    void getDiagonalAccessibleFields(
      Position initial_position, 
      Field board[BOARD_DIMENSIONS][BOARD_DIMENSIONS], 
      bool access_map[BOARD_DIMENSIONS][BOARD_DIMENSIONS],
      unsigned int max_distance = std::numeric_limits<unsigned int>::max()
    );

    virtual void getAccessibleFields(
      Position,
      Field[BOARD_DIMENSIONS][BOARD_DIMENSIONS],
      bool[BOARD_DIMENSIONS][BOARD_DIMENSIONS]
    ) = 0;

  public:
    Piece();
    const bool isWhite();
    const char getSymbol();
    const bool moveIsPossible(Field[BOARD_DIMENSIONS][BOARD_DIMENSIONS], Position, Position);
    
};

#endif

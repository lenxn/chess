#ifndef PIECE_H_INCLUDED
#define PIECE_H_INCLUDED

#include <limits>
#include <string>

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

    //--------------------------------------------------------------------------
    // Marks wether the pawn was already moved during this game.
    //
    bool initial_position_;

  	bool is_white_;
    std::string symbol_;

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

    //--------------------------------------------------------------------------
    // Get Accessible Fields.
    // Takes a boolean matrix of board dimensions and sets all elements which 
    // are accessible by the respective piece from the respective position.
    //
    virtual void getAccessibleFields(
      Position,
      Field[BOARD_DIMENSIONS][BOARD_DIMENSIONS],
      bool[BOARD_DIMENSIONS][BOARD_DIMENSIONS]
    ) = 0;

  public:
    Piece();
    Piece(const bool, const char);
    const bool isWhite();
    const std::string getSymbol();
    const bool moveIsPossible(Field[BOARD_DIMENSIONS][BOARD_DIMENSIONS], Position, Position);

    //--------------------------------------------------------------------------
    // Mark as Moved.
    // Some moves are no more possible after leaving the initial position.
    //
    void markAsMoved();
    
};

#endif

//------------------------------------------------------------------------------
// CannotTakeOwnPieceException.h
//
// Author: Stefan Lengauer
//------------------------------------------------------------------------------
//

#ifndef CANNOT_TAKE_OWN_PIECE_EXCEPTION_H
#define CANNOT_TAKE_OWN_PIECE_EXCEPTION_H

#include <exception>

//------------------------------------------------------------------------------
// CannotTakeOwnPieceException
// class to demonstrate the Exception for empty fields
//
class CannotTakeOwnPieceException : public std::exception
{
  public:

    //--------------------------------------------------------------------------
    // Constructor
    //
    CannotTakeOwnPieceException();

    //--------------------------------------------------------------------------
    // Destructor
    //
    virtual ~CannotTakeOwnPieceException() throw();
};

#endif

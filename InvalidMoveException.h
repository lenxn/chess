//------------------------------------------------------------------------------
// InvalidMoveException.h
//
// Author: Stefan Lengauer
//------------------------------------------------------------------------------
//

#ifndef INVALID_MOVE_EXCEPTION_H
#define INVALID_MOVE_EXCEPTION_H

#include <exception>

//------------------------------------------------------------------------------
// InvalidMoveException
// class to demonstrate the Exception for empty fields
//
class InvalidMoveException : public std::exception
{
  public:

    //--------------------------------------------------------------------------
    // Constructor
    //
    InvalidMoveException();

    //--------------------------------------------------------------------------
    // Destructor
    //
    virtual ~InvalidMoveException() throw();
};

#endif

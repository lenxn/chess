//------------------------------------------------------------------------------
// NoPieceException.h
//
// Author: Stefan Lengauer
//------------------------------------------------------------------------------
//

#ifndef NO_PIECE_EXCEPTION_H
#define NO_PIECE_EXCEPTION_H

#include <exception>

//------------------------------------------------------------------------------
// NoPieceException
// class to demonstrate the Exception for empty fields
//
class NoPieceException : public std::exception
{
  public:

    //--------------------------------------------------------------------------
    // Constructor
    //
    NoPieceException();

    //--------------------------------------------------------------------------
    // Destructor
    //
    virtual ~NoPieceException() throw();
};

#endif

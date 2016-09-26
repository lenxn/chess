//------------------------------------------------------------------------------
// WrongPlayerException.h
//
// Author: Stefan Lengauer
//------------------------------------------------------------------------------
//

#ifndef WRONG_PLAYER_EXCEPTION_H
#define WRONG_PLAYER_EXCEPTION_H

#include <exception>

//------------------------------------------------------------------------------
// WrongPlayerException
// class to demonstrate the Exception for empty fields
//
class WrongPlayerException : public std::exception
{
  public:

    //--------------------------------------------------------------------------
    // Constructor
    //
    WrongPlayerException();

    //--------------------------------------------------------------------------
    // Destructor
    //
    virtual ~WrongPlayerException() throw();
};

#endif

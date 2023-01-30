#ifndef CHESSGAME_H
#define CHESSGAME_H

#include <cstdlib>

#include "Board.h"
#include "Piece.h"


class ChessGame{
public:
    ChessGame();
    ~ChessGame();

    ChessGame(const ChessGame &) = default;	//Copy constructor
    ChessGame &operator=(const ChessGame &) = default;	//Copy assignment
    ChessGame(ChessGame &&) = default;	//Move constructor
    ChessGame &operator=(ChessGame &&) = default;	// Move assignment

    void play();

private:
    Board* boardPtr;

    void printCheckMessage() const;


};

#endif // CHESSGAME_H
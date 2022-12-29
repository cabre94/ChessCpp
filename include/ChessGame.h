#ifndef CHESSGAME_HPP
#define CHESSGAME_HPP

#include <cstdlib>
#include "Piece.hpp"


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

    void printCheckMessage();


};

#endif
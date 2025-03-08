#pragma once

#include <cstdlib>

#include "Boards/Board.h"
#include "Pieces/Piece.h"

namespace chess {

class ChessGame {
public:
    ChessGame();
    ~ChessGame();

    ChessGame(const ChessGame &) = default;            // Copy constructor
    ChessGame &operator=(const ChessGame &) = default; // Copy assignment
    ChessGame(ChessGame &&) = default;                 // Move constructor
    ChessGame &operator=(ChessGame &&) = default;      // Move assignment

    void play();

private:
    Board *boardPtr;

    void printCheckMessage() const;
};

} // namespace chess
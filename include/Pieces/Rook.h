#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"

class Rook : public Piece{
public:
    Rook(PieceColour C);
    ~Rook();

    void printPiece();

    std::set<std::string> getPossibleMoves(Board *board, std::string from);
};

#endif // ROOK_H
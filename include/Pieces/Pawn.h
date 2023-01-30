#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"

class Pawn : public Piece{
public:
    Pawn(PieceColor C);
    ~Pawn();

    void printPiece();
    std::string getName();

    std::set<std::string> getPossibleMoves(Board  *board, std::string from);
};

#endif // PAWN_H

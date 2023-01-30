#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"

class Pawn : public Piece{
public:
    Pawn(PieceColor color_, Position pos_) : Piece(color_, "PAWN", pos_) {}
    ~Pawn() {}

    void printPiece() const override;
    std::set<std::string> getPossibleMoves(const Board *board) const override;
};

#endif // PAWN_H
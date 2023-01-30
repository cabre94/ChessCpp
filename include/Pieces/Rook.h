#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"

class Rook : public Piece{
public:
    Rook(PieceColor color_, Position pos_) : Piece(color_, "ROOK", pos_) {}
    ~Rook() {}

    void printPiece() const override;
    std::set<std::string> getPossibleMoves(const Board *board) const override;
};

#endif // ROOK_H
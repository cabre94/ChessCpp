#ifndef KING_H
#define KING_H

#include "Piece.h"

class King : public Piece{
public:
    King(PieceColor color_, Position pos_) : Piece(color_, "KING", pos_) {}
    ~King() {}

    void printPiece() const override;
    std::set<std::string> getPossibleMoves(const Board *board) const override;
};

#endif // KING_H

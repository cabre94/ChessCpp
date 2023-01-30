#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"

class Bishop : public Piece{
public:
    Bishop(PieceColor color_, Position pos_) : Piece(color_, "BISHOP", pos_) {}
    ~Bishop() {}

    void printPiece() const override;
    std::set<std::string> getPossibleMoves(const Board *board) const override;
};

#endif // BISHOP_H
#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"

class Queen : public Piece{
public:
    Queen(PieceColor color_, Position pos_) : Piece(color_, "QUEEN", pos_) {} 
    ~Queen() {}

    void printPiece() const override;
    std::set<std::string> getPossibleMoves(const Board *board) const override;
};

#endif // QUEEN_H
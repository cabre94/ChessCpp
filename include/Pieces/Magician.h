#ifndef MAGICIAN_H
#define MAGICIAN_H

#include "Piece.h"

class Magician : public Piece{
public:
    Magician(PieceColor color_, Position pos_) :Piece(color_,"MAGICIAN", pos_) {}
    ~Magician() {}

    void printPiece() const override;
    std::set<std::string> getPossibleMoves(const Board *board) const override;
};

#endif // MAGICIAN_H
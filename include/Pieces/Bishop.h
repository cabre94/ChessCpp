#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"

class Bishop : public Piece{
public:
    Bishop(PlayerID player_id_, Position pos_) : Piece(player_id_, "BISHOP", pos_) {}
    ~Bishop() {}

    void printPiece() const override;
    std::set<std::string> getPossibleMoves(const Board *board) const override;
};

#endif // BISHOP_H
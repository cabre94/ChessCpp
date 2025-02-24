#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"

class Queen : public Piece{
public:
    Queen(PlayerID player_id_, Position pos_) : Piece(player_id_, "QUEEN", pos_) {} 
    ~Queen() {}

    void printPiece() const override;
    std::set<std::string> getPossibleMoves(const Board *board) const override;
};

#endif // QUEEN_H
#pragma once

#include "Pieces/Piece.h"
#include "Positions/Position.h"

namespace chess {

class Bishop : public Piece {
public:
    Bishop(PlayerID player_id_, Position pos_) : Piece(player_id_, "BISHOP", pos_) {}
    ~Bishop() {}

    void printPiece() const override;
    std::set<Position> getPossibleMoves(const Board *board) const override;
};

} // namespace chess
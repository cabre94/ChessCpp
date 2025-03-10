#pragma once

#include "Pieces/Piece.h"

namespace chess {

class Queen : public Piece {
public:
    Queen(PlayerID player_id_, Position pos_) : Piece(player_id_, "QUEEN", pos_) {}
    ~Queen() {}

    std::set<Position> getPossibleMoves(const Board *board) const override;
};

} // namespace chess
#pragma once

#include "Pieces/Piece.h"

namespace chess {

class Champion : public Piece {
public:
    Champion(PlayerID player_id_, Position pos_) : Piece(player_id_, "CHAMPION", pos_) {}
    ~Champion() {}

    std::set<Position> getPossibleMoves(const Board *board) const override;
};

} // namespace chess
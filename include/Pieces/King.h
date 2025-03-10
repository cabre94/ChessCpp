#pragma once

#include "Pieces/Piece.h"

namespace chess {

class King : public Piece {
public:
    King(PlayerID player_id_, Position pos_) : Piece(player_id_, "KING", pos_) {}
    ~King() {}

    std::set<Position> getPossibleMoves(const Board *board) const override;
};

} // namespace chess
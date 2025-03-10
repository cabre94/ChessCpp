#pragma once

#include "Pieces/Piece.h"

namespace chess {

class Knight : public Piece {
public:
    Knight(PlayerID player_id_, Position pos_) : Piece(player_id_, "KNIGHT", pos_) {}
    ~Knight() {}

    std::set<Position> getPossibleMoves(const Board *board) const override;
};

} // namespace chess
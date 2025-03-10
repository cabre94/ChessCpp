#pragma once

#include "Pieces/Piece.h"
#include "Pieces/Utils.h"
#include "Positions/Position.h"

namespace chess {

class Bishop : public Piece {
public:
    Bishop(PlayerID player_id_, Position pos_) : Piece(player_id_, "BISHOP", pos_) {}
    ~Bishop() {}

    std::set<Position> getPossibleMoves(const Board *board) const override;
};

} // namespace chess
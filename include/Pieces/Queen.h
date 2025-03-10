#pragma once

#include "Pieces/Piece.h"
#include "Pieces/Utils.h"
#include "Positions/Position.h"

namespace chess {

class Queen : public Piece {
public:
    Queen(PlayerID player_id_, Position pos_)
        : Piece(player_id_, QUEEN_NAME,
                (player_id_ == WHITE) ? QUEEN_WHITE_SYMBOL : QUEEN_BLACK_SYMBOL, pos_) {}
    ~Queen() {}

    std::set<Position> getPossibleMoves(const Board *board) const override;
};

} // namespace chess
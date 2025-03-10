#pragma once

#include "Pieces/Piece.h"
#include "Pieces/Utils.h"
#include "Positions/Position.h"

namespace chess {

class Knight : public Piece {
public:
    Knight(PlayerID player_id_, Position pos_)
        : Piece(player_id_, KNIGHT_NAME,
                (player_id_ == WHITE) ? KNIGHT_WHITE_SYMBOL : KNIGHT_BLACK_SYMBOL, pos_) {}
    ~Knight() {}

    std::set<Position> getPossibleMoves(const Board *board) const override;
};

} // namespace chess
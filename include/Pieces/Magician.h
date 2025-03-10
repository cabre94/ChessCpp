#pragma once

#include "Pieces/Piece.h"
#include "Pieces/Utils.h"
#include "Positions/Position.h"

namespace chess {

class Magician : public Piece {
public:
    Magician(PlayerID player_id_, Position pos_)
        : Piece(player_id_, MAGICIAN_NAME,
                (player_id_ == WHITE) ? MAGICIAN_WHITE_SYMBOL : MAGICIAN_BLACK_SYMBOL, pos_) {}
    ~Magician() {}

    std::set<Position> getPossibleMoves(const Board *board) const override;
};

} // namespace chess
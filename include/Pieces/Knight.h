#pragma once

#include "Piece.h"

namespace chess {

class Knight : public Piece{
public:
    Knight(PlayerID player_id_, Position pos_) : Piece(player_id_, "KNIGHT", pos_) {}
    ~Knight() {}

    void printPiece() const override;
    std::set<std::string> getPossibleMoves(const Board *board) const override;
};

} // namespace chess
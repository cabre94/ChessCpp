#pragma once

#include "Pieces/Piece.h"

namespace chess {

class Rook : public Piece {
public:
    Rook(PlayerID player_id_, Position pos_) : Piece(player_id_, "ROOK", pos_) {}
    ~Rook() {}

    void printPiece() const override;
    std::set<std::string> getPossibleMoves(const Board *board) const override;
};

} // namespace chess
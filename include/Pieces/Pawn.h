#pragma once

#include "Piece.h"

namespace chess {

class Pawn : public Piece {
public:
    Pawn(PlayerID player_id_, Position pos_) : Piece(player_id_, "PAWN", pos_) {}
    ~Pawn() {}

    void printPiece() const override;
    std::set<std::string> getPossibleMoves(const Board *board) const override;
};

} // namespace chess
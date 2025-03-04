#pragma once

#include "Pieces/Piece.h"

namespace chess {

class Magician : public Piece {
public:
    Magician(PlayerID player_id_, Position pos_) : Piece(player_id_, "MAGICIAN", pos_) {}
    ~Magician() {}

    void printPiece() const override;
    std::set<std::string> getPossibleMoves(const Board *board) const override;
};

} // namespace chess
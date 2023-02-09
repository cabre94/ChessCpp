#ifndef KING_H
#define KING_H

#include "Piece.h"

class King : public Piece{
public:
    King(PlayerID player_id_, Position pos_) : Piece(player_id_, "KING", pos_) {}
    ~King() {}

    void printPiece() const override;
    std::set<std::string> getPossibleMoves(const Board *board) const override;
};

#endif // KING_H

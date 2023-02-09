#ifndef CHAMPION_H
#define CHAMPION_H

#include "Piece.h"

class Champion : public Piece{
public:
    Champion(PlayerID player_id_, Position pos_) : Piece(player_id_, "CHAMPION", pos_){}
    ~Champion() {}

    void printPiece() const override;
    std::set<std::string> getPossibleMoves(const Board *board) const override;
};

#endif // CHAMPION_H
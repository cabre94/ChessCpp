#ifndef CHAMPION_H
#define CHAMPION_H

#include "Piece.h"

class Champion : public Piece{
public:
    Champion(PieceColor C);
    ~Champion();

    void printPiece();

    std::set<std::string> getPossibleMoves(Board *board, std::string from);
};

#endif // CHAMPION_H
#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"

class Queen : public Piece{
public:
    Queen(PieceColour C);
    ~Queen();

    void printPiece();

    std::set<std::string> getPossibleMoves(Board *board, std::string from);
};


#endif // QUEEN_H
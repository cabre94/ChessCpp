#ifndef KING_H
#define KING_H

#include "Piece.h"

class King : public Piece{
public:
    King(PieceColor C);
    ~King();

    void printPiece();

    std::set<std::string> getPossibleMoves(Board *board, std::string from);
};

#endif // KING_H

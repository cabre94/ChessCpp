#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"

class Bishop : public Piece{
public:
    Bishop(PieceColor C);
    ~Bishop();

    void printPiece();

    std::set<std::string> getPossibleMoves(Board *board, std::string from);
};

#endif // BISHOP_H
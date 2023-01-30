#ifndef MAGICIAN_H
#define MAGICIAN_H

#include "Piece.h"

class Magician : public Piece{
public:
    Magician(PieceColor C);
    ~Magician();

    void printPiece();

    std::set<std::string> getPossibleMoves(Board *board, std::string from);
};

#endif // MAGICIAN_H
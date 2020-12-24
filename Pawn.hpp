#ifndef PAWN_HPP
#define PAWN_HPP

#include "Piece.hpp"

class Pawn : public Piece{
public:
    Pawn(PieceColour C);
    ~Pawn();

    void printPiece();
    std::string getName();

    std::set<std::string> getPossibleMoves(Board  *board, std::string from);
};

#endif

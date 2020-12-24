#ifndef ROOK_HPP
#define ROOK_HPP

#include "Piece.hpp"

class Rook : public Piece{
public:
    Rook(PieceColour C);
    ~Rook();

    bool validMove(std::string newPos);

    void printPiece();

    std::set<std::string> getPossibleMoves(Board *board, std::string from);
};

#endif
#ifndef KNIGHT_HPP
#define KNIGHT_HPP

#include "Piece.hpp"

class Knight : public Piece{
public:
    Knight(PieceColour C);
    ~Knight();

    void printPiece();

    std::set<std::string> getPossibleMoves(Board *board, std::string from);
};

#endif
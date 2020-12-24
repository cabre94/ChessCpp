#ifndef KNIGHT_HPP
#define KNIGHT_HPP

#include "Piece.hpp"

class Knight : public Piece{
public:
    Knight(PieceColour C);
    ~Knight();

    bool validMove(std::string newPos);

    void printPiece();

    std::set<std::string> getPossibleMoves(Board *board, std::string from);
};

#endif
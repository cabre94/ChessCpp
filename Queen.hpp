#ifndef QUEEN_HPP
#define QUEEN_HPP

#include "Piece.hpp"

class Queen : public Piece{
public:
    Queen(PieceColour C);
    ~Queen();

    void printPiece();

    std::set<std::string> getPossibleMoves(Board *board, std::string from);
};


#endif
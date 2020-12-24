#ifndef CHAMPION_HPP
#define CHAMPION_HPP

#include "Piece.hpp"

class Champion : public Piece{
public:
    Champion(PieceColour C);
    ~Champion();

    void printPiece();

    std::set<std::string> getPossibleMoves(Board *board, std::string from);
};

#endif
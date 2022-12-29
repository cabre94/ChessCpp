#ifndef MAGICIAN_HPP
#define MAGICIAN_HPP

#include "Piece.hpp"

class Magician : public Piece{
public:
    Magician(PieceColour C);
    ~Magician();

    void printPiece();

    std::set<std::string> getPossibleMoves(Board *board, std::string from);
};

#endif
#ifndef MAGICIAN_HPP
#define MAGICIAN_HPP

#include "Piece.hpp"

class Magician : public Piece{
public:
    Magician(PieceColour C);
    ~Magician();

    bool validMove(std::string newPos);

    void printPiece();

    std::set<std::string> getPossibleMoves(Board *board, std::string from);
};

#endif
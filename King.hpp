#ifndef KING_HPP
#define KING_HPP

#include "Piece.hpp"

class King : public Piece{
public:
    King(PieceColour C);
    ~King();

    bool validMove(std::string newPos);

    void printPiece();

    std::set<std::string> getPossibleMoves(Board *board, std::string from);
};

#endif

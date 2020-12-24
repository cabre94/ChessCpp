#ifndef BISHOP_HPP
#define BISHOP_HPP

#include "Piece.hpp"

class Bishop : public Piece{
public:
    Bishop(PieceColour C);
    ~Bishop();

    void printPiece();

    std::set<std::string> getPossibleMoves(Board *board, std::string from);
};

#endif
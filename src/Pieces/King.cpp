#include "Board.h"
#include "King.h"

void King::printPiece() const{
    if(color == WHITE)
        std::cout << "♔";
    else
        std::cout << "♚";
}

std::set<std::string> King::getPossibleMoves(const Board *board) const{
    std::set<std::string> validMoves;
    // validMoves = board->getValidMoves(pos, KING); // TODO
    return validMoves;
}


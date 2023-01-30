#include "Board.h"
#include "Queen.h"

void Queen::printPiece() const {
    if(color == WHITE)
        std::cout << "♕";
    else
        std::cout << "♛";
}

std::set<std::string> Queen::getPossibleMoves(const Board *board) const {
    std::set<std::string> validMoves;
    // validMoves = board->getValidMoves(from, QUEEN); // TODO
    return validMoves;
}
#include "Board.h"
#include "Magician.h"

void Magician::printPiece() const {
    if(color == WHITE)
        std::cout << "♽";
    else
        std::cout << "♼";
}

std::set<std::string> Magician::getPossibleMoves(const Board *board) const {
    std::set<std::string> validMoves;
    // validMoves = board->getValidMoves(from, MAGICIAN); // TODO
    return validMoves;
}
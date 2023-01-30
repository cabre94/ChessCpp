#include "Board.h"
#include "Rook.h"

void Rook::printPiece() const {
    if(color == WHITE)
        std::cout << "♖";
    else
        std::cout << "♜";
}

std::set<std::string> Rook::getPossibleMoves(const Board *board) const {
    std::set<std::string> validMoves;
    // validMoves = board->getValidMoves(from, ROOK); // TODO
    return validMoves;
}
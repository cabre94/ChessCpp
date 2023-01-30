#include "Board.h"
#include "Pawn.h"

void Pawn::printPiece() const {
    if(color == WHITE)
        std::cout << "♙";
    else
        std::cout << "♟︎";
}

std::set<std::string> Pawn::getPossibleMoves(const Board *board) const {
    std::set<std::string> validMoves;
    // validMoves = board->getValidMoves(from, PAWN); // TODO
    return validMoves;
}
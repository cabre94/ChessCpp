#include "Pawn.h"
#include "Board.h"

namespace chess {

void Pawn::printPiece() const {
    if (player_id == WHITE)
        std::cout << "♙";
    else
        std::cout << "♟︎";
}

std::set<std::string> Pawn::getPossibleMoves(const Board *board) const {
    std::set<std::string> validMoves;
    // validMoves = board->getValidMoves(from, PAWN); // TODO
    return validMoves;
}

} // namespace chess
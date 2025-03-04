#include "Pieces/Queen.h"
#include "Boards/Board.h"

namespace chess {

void Queen::printPiece() const {
    if (player_id == WHITE)
        std::cout << "♕";
    else
        std::cout << "♛";
}

std::set<std::string> Queen::getPossibleMoves(const Board *board) const {
    std::set<std::string> validMoves;
    // validMoves = board->getValidMoves(from, QUEEN); // TODO
    return validMoves;
}

} // namespace chess
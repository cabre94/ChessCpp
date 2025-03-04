#include "Pieces/Knight.h"
#include "Boards/Board.h"

namespace chess {

void Knight::printPiece() const {
    if (player_id == WHITE)
        std::cout << "♘";
    else
        std::cout << "♞";
}

std::set<std::string> Knight::getPossibleMoves(const Board *board) const {
    std::set<std::string> validMoves;
    // validMoves = board->getValidMoves(pos_, KNIGHT); // TODO
    return validMoves;
}

} // namespace chess
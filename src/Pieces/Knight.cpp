#include "Pieces/Knight.h"
#include "Boards/Board.h"

namespace chess {

void Knight::printPiece() const {
    if (player_id == WHITE)
        std::cout << "♘";
    else
        std::cout << "♞";
}

std::set<Position> Knight::getPossibleMoves(const Board *board) const {
    std::set<Position> validMoves;
    // validMoves = board->getValidMoves(pos_, KNIGHT); // TODO
    return validMoves;
}

} // namespace chess
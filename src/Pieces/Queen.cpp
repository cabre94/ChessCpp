#include "Pieces/Queen.h"
#include "Boards/Board.h"

namespace chess {

std::set<Position> Queen::getPossibleMoves(const Board *board) const {
    (void) board;
    std::set<Position> validMoves;
    // validMoves = board->getValidMoves(from, QUEEN); // TODO
    return validMoves;
}

} // namespace chess
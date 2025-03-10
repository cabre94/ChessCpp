#include "Pieces/Rook.h"
#include "Boards/Board.h"

namespace chess {

std::set<Position> Rook::getPossibleMoves(const Board *board) const {
    (void) board;
    std::set<Position> validMoves;
    // validMoves = board->getValidMoves(from, ROOK); // TODO
    return validMoves;
}

} // namespace chess
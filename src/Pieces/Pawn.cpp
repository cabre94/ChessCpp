#include "Pieces/Pawn.h"
#include "Boards/Board.h"
#include "Positions/Position.h"

namespace chess {

std::set<Position> Pawn::getPossibleMoves(const Board *board) const {
    (void) board;
    std::set<Position> validMoves;
    // validMoves = board->getValidMoves(from, PAWN); // TODO
    return validMoves;
}

} // namespace chess
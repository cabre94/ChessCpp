#include "Pieces/Bishop.h"
#include "Boards/Board.h"
#include "Positions/Position.h"

namespace chess {

void Bishop::printPiece() const {
    if (player_id == WHITE)
        std::cout << "♗";
    else
        std::cout << "♝";
}

std::set<std::string> Bishop::getPossibleMoves(const Board *board) const {
    std::set<std::string> validMoves;

    // validMoves = board->getValidMoves(pos, BISHOP); // TODO

    return validMoves;
}

} // namespace chess
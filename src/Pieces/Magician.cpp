#include "Pieces/Magician.h"
#include "Boards/Board.h"

namespace chess {

void Magician::printPiece() const {
    if (player_id == WHITE)
        std::cout << "♽";
    else
        std::cout << "♼";
}

std::set<Position> Magician::getPossibleMoves(const Board *board) const {
	(void) board;
    std::set<Position> validMoves;
    // validMoves = board->getValidMoves(from, MAGICIAN); // TODO
    return validMoves;
}

} // namespace chess
#include "Pieces/King.h"
#include "Boards/Board.h"

namespace chess {

void King::printPiece() const {
    if (player_id == WHITE)
        std::cout << "♔";
    else
        std::cout << "♚";
}

std::set<Position> King::getPossibleMoves(const Board *board) const {
	(void) board;
    std::set<Position> validMoves;
    // validMoves = board->getValidMoves(pos, KING); // TODO
    return validMoves;
}

} // namespace chess
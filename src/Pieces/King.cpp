#include "Pieces/King.h"
#include "Boards/Board.h"

namespace chess {

void King::printPiece() const {
    if (player_id == WHITE)
        std::cout << "♔";
    else
        std::cout << "♚";
}

std::set<std::string> King::getPossibleMoves(const Board *board) const {
    std::set<std::string> validMoves;
    // validMoves = board->getValidMoves(pos, KING); // TODO
    return validMoves;
}

} // namespace chess
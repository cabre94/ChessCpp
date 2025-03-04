#include "Pieces/Rook.h"
#include "Boards/Board.h"

namespace chess {

void Rook::printPiece() const {
    if (player_id == WHITE)
        std::cout << "♖";
    else
        std::cout << "♜";
}

std::set<std::string> Rook::getPossibleMoves(const Board *board) const {
    std::set<std::string> validMoves;
    // validMoves = board->getValidMoves(from, ROOK); // TODO
    return validMoves;
}

} // namespace chess
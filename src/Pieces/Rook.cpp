#include "Pieces/Rook.h"
#include "Boards/Board.h"

namespace chess {

// void Rook::printPiece() const {
//     if (player_id == WHITE)
//         std::cout << "♖";
//     else
//         std::cout << "♜";
// }

std::set<Position> Rook::getPossibleMoves(const Board *board) const {
    (void) board;
    std::set<Position> validMoves;
    // validMoves = board->getValidMoves(from, ROOK); // TODO
    return validMoves;
}

} // namespace chess
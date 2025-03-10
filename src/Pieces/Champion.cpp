#include "Pieces/Champion.h"
#include "Boards/Board.h"

namespace chess {

// void Champion::printPiece() const {
//     if (player_id == WHITE)
//         std::cout << "☆";
//     else
//         std::cout << "★";
// }

std::set<Position> Champion::getPossibleMoves(const Board *board) const {
    (void) board;
    std::set<Position> validMoves;
    // validMoves = board->getValidMoves(pos, CHAMPION); // TODO
    return validMoves;
}

} // namespace chess
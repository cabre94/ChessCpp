#include "Magician.h"
#include "Board.h"

namespace chess {

void Magician::printPiece() const {
    if (player_id == WHITE)
        std::cout << "♽";
    else
        std::cout << "♼";
}

std::set<std::string> Magician::getPossibleMoves(const Board *board) const {
    std::set<std::string> validMoves;
    // validMoves = board->getValidMoves(from, MAGICIAN); // TODO
    return validMoves;
}

} // namespace chess
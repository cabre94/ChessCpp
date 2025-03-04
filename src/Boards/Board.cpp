#include "Boards/Board.h"

namespace chess {

Board::Board() {
    gameEnded = false;
    whiteInCheck = false;
    blackInCheck = false;
}

bool Board::stringInSet(const std::set<std::string> &set, const std::string &str) const {
    return bool(set.count(str));
}

void Board::addPlayerPieces(std::vector<Piece *> &player_pieces) {
    all_pieces.push_back(&player_pieces);
}

} // namespace chess
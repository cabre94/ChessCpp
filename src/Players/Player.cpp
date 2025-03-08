#include "Players/Player.h"

namespace chess {

Player::~Player() {
    Piece *piece;

    while (!pieces.empty()) {
        piece = pieces.back();
        pieces.pop_back();
        delete piece;
    }
}

} // namespace chess
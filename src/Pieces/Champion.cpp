#include "Board.h"
#include "Champion.h"

void Champion::printPiece() const {
    if(player_id == WHITE)
        std::cout << "☆";
    else
        std::cout << "★";
}

std::set<std::string> Champion::getPossibleMoves(const Board *board) const {
    std::set<std::string> validMoves;
    // validMoves = board->getValidMoves(pos, CHAMPION); // TODO
    return validMoves;
}
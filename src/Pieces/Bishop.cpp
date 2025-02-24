#include "Board.h"
#include "Bishop.h"

void Bishop::printPiece() const {
    if(player_id == WHITE)
        std::cout << "♗";
    else
        std::cout << "♝";
}

std::set<std::string> Bishop::getPossibleMoves(const Board *board) const {
    std::set<std::string> validMoves;

    // validMoves = board->getValidMoves(pos, BISHOP); // TODO
    
	return validMoves;
}


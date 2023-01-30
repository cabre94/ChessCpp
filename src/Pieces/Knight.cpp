#include "Board.h"
#include "Knight.h"

Knight::Knight(PieceColor C):Piece(C,KNIGHT,"KNIGHT"){}

Knight::~Knight(){}

void Knight::printPiece(){
    if(color == WHITE)
        std::cout << "♘";
    else
        std::cout << "♞";
}

std::set<std::string> Knight::getPossibleMoves(Board *board, std::string from){
    std::set<std::string> validMoves;
    validMoves = board->getValidMoves(from, KNIGHT);
    return validMoves;
}


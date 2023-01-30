#include "Board.h"
#include "Rook.h"

Rook::Rook(PieceColor C):Piece(C,ROOK,"ROOK"){}

Rook::~Rook(){}

void Rook::printPiece(){
    if(color == WHITE)
        std::cout << "♖";
    else
        std::cout << "♜";
}

std::set<std::string> Rook::getPossibleMoves(Board *board, std::string from){
    std::set<std::string> validMoves;
    validMoves = board->getValidMoves(from, ROOK);
    return validMoves;
}
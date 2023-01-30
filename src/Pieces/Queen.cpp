/*
date: 21-12-2020
File: Queen.cpp
Author : Facundo Martin Cabrera
Email: cabre94@hotmail.com facundo.cabrera@ib.edu.ar
GitHub: https://github.com/cabre94
GitLab: https://gitlab.com/cabre94
Description:
*/

#include "Board.h"
#include "Queen.h"

Queen::Queen(PieceColor C):Piece(C,QUEEN,"QUEEN"){}

Queen::~Queen(){}

void Queen::printPiece(){
    if(color == WHITE)
        std::cout << "♕";
    else
        std::cout << "♛";
}

std::set<std::string> Queen::getPossibleMoves(Board *board, std::string from){
    std::set<std::string> validMoves;
    validMoves = board->getValidMoves(from, QUEEN);
    return validMoves;
}
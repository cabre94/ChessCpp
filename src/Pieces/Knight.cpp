/*
date: 21-12-2020
File: Knight.cpp
Author : Facundo Martin Cabrera
Email: cabre94@hotmail.com facundo.cabrera@ib.edu.ar
GitHub: https://github.com/cabre94
GitLab: https://gitlab.com/cabre94
Description:
*/

#include "Board.h"
#include "Knight.h"

Knight::Knight(PieceColour C):Piece(C,KNIGHT,"KNIGHT"){}

Knight::~Knight(){}

void Knight::printPiece(){
    if(colour == WHITE)
        std::cout << "♘";
    else
        std::cout << "♞";
}

std::set<std::string> Knight::getPossibleMoves(Board *board, std::string from){
    std::set<std::string> validMoves;
    validMoves = board->getValidMoves(from, KNIGHT);
    return validMoves;
}


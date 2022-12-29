/*
date: 21-12-2020
File: Pawn.cpp
Author : Facundo Martin Cabrera
Email: cabre94@hotmail.com facundo.cabrera@ib.edu.ar
GitHub: https://github.com/cabre94
GitLab: https://gitlab.com/cabre94
Description:
*/

#include "Board.h"
#include "Pawn.h"

Pawn::Pawn(PieceColour C):Piece(C,PAWN,"PAWN") {}

Pawn::~Pawn(){}

void Pawn::printPiece(){
    if(colour == WHITE)
        std::cout << "♙";
    else
        std::cout << "♟︎";
}

std::set<std::string> Pawn::getPossibleMoves(Board *board, std::string from){
    std::set<std::string> validMoves;
    validMoves = board->getValidMoves(from, PAWN);
    return validMoves;
}

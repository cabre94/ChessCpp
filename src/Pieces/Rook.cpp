/*
date: 21-12-2020
File: Rook.cpp
Author : Facundo Martin Cabrera
Email: cabre94@hotmail.com facundo.cabrera@ib.edu.ar
GitHub: https://github.com/cabre94
GitLab: https://gitlab.com/cabre94
Description:
*/

#include "Board.h"
#include "Rook.h"

Rook::Rook(PieceColour C):Piece(C,ROOK,"ROOK"){}

Rook::~Rook(){}

void Rook::printPiece(){
    if(colour == WHITE)
        std::cout << "♖";
    else
        std::cout << "♜";
}

std::set<std::string> Rook::getPossibleMoves(Board *board, std::string from){
    std::set<std::string> validMoves;
    validMoves = board->getValidMoves(from, ROOK);
    return validMoves;
}


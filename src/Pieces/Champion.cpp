/*
date: 24-12-2020
File: Champion.cpp
Author : Facundo Martin Cabrera
Email: cabre94@hotmail.com facundo.cabrera@ib.edu.ar
GitHub: https://github.com/cabre94
GitLab: https://gitlab.com/cabre94
Description:
*/

#include "Board.h"
#include "Champion.h"

Champion::Champion(PieceColor C):Piece(C,CHAMPION,"CHAMPION"){}

Champion::~Champion(){}

void Champion::printPiece(){
    if(color == WHITE)
        std::cout << "☆";
    else
        std::cout << "★";
}

std::set<std::string> Champion::getPossibleMoves(Board *board, std::string from){
    std::set<std::string> validMoves;
    validMoves = board->getValidMoves(from, CHAMPION);
    return validMoves;
}
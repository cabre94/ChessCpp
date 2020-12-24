/*
date: 21-12-2020
File: Bishop.cpp
Author : Facundo Martin Cabrera
Email: cabre94@hotmail.com facundo.cabrera@ib.edu.ar
GitHub: https://github.com/cabre94
GitLab: https://gitlab.com/cabre94
Description:
*/

#include "Bishop.hpp"

Bishop::Bishop(PieceColour C):Piece(C,BISHOP,"BISHOP"){}

Bishop::~Bishop(){}

bool Bishop::validMove(std::string newPos){
    // TODO completar funcion
    return true;
}

void Bishop::printPiece(){
    if(colour == WHITE)
        std::cout << "♗";
        // std::cout << "\u2659";
    else
        std::cout << "♝";
        // std::cout << "\u265F";
}

std::set<std::string> Bishop::getPossibleMoves(Board *board, std::string from){
    std::set<std::string> validMoves;
    validMoves = board->getValidMoves(from, BISHOP);
    return validMoves;
}


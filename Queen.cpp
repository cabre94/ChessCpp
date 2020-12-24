/*
date: 21-12-2020
File: Queen.cpp
Author : Facundo Martin Cabrera
Email: cabre94@hotmail.com facundo.cabrera@ib.edu.ar
GitHub: https://github.com/cabre94
GitLab: https://gitlab.com/cabre94
Description:
*/

#include "Queen.hpp"

Queen::Queen(PieceColour C):Piece(C,QUEEN,"QUEEN"){}

Queen::~Queen(){}

bool Queen::validMove(std::string newPos){
    // TODO completar funcion
    return true;
}

void Queen::printPiece(){
    if(colour == WHITE)
        std::cout << "♕";
        // std::cout << "\u2659";
    else
        std::cout << "♛";
        // std::cout << "\u265F";
}

std::set<std::string> Queen::getPossibleMoves(Board *board, std::string from){
    std::set<std::string> validMoves;
    validMoves = board->getValidMoves(from, QUEEN);
    return validMoves;
}

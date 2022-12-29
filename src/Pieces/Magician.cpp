/*
date: 24-12-2020
File: Magician.cpp
Author : Facundo Martin Cabrera
Email: cabre94@hotmail.com facundo.cabrera@ib.edu.ar
GitHub: https://github.com/cabre94
GitLab: https://gitlab.com/cabre94
Description:
*/

#include "Magician.hpp"

Magician::Magician(PieceColour C):Piece(C,MAGICIAN,"MAGICIAN"){}

Magician::~Magician(){}

void Magician::printPiece(){
    if(colour == WHITE)
        std::cout << "♽";
    else
        std::cout << "♼";
}

std::set<std::string> Magician::getPossibleMoves(Board *board, std::string from){
    std::set<std::string> validMoves;
    validMoves = board->getValidMoves(from, MAGICIAN);
    return validMoves;
}
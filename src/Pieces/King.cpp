/*
date: 21-12-2020
File: King.cpp
Author : Facundo Martin Cabrera
Email: cabre94@hotmail.com facundo.cabrera@ib.edu.ar
GitHub: https://github.com/cabre94
GitLab: https://gitlab.com/cabre94
Description:
*/

#include "King.hpp"

King::King(PieceColour C):Piece(C,KING,"KING"){}

King::~King(){}

void King::printPiece(){
    if(colour == WHITE)
        std::cout << "♔";
    else
        std::cout << "♚";
}

std::set<std::string> King::getPossibleMoves(Board *board, std::string from){
    std::set<std::string> validMoves;
    validMoves = board->getValidMoves(from, KING);
    return validMoves;
}


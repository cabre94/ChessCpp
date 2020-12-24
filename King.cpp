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

bool King::validMove(std::string newPos){
    // TODO completar funcion
    return true;
}

void King::printPiece(){
    if(colour == WHITE)
        std::cout << "♔";
        // std::cout << "\u2659";
    else
        std::cout << "♚";
        // std::cout << "\u265F";
}

std::set<std::string> King::getPossibleMoves(Board *board, std::string from){
    std::set<std::string> validMoves;
    validMoves = board->getValidMoves(from, KING);
    return validMoves;
}


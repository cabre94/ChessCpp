/*
date: 21-12-2020
File: Knight.cpp
Author : Facundo Martin Cabrera
Email: cabre94@hotmail.com facundo.cabrera@ib.edu.ar
GitHub: https://github.com/cabre94
GitLab: https://gitlab.com/cabre94
Description:
*/

#include "Knight.hpp"

Knight::Knight(PieceColour C):Piece(C,KNIGHT,"KNIGHT"){}

Knight::~Knight(){}

bool Knight::validMove(std::string newPos){
    // TODO completar funcion
    return true;
}

void Knight::printPiece(){
    if(colour == WHITE)
        std::cout << "♘";
        // std::cout << "\u2659";
    else
        std::cout << "♞";
        // std::cout << "\u265F";
}

std::set<std::string> Knight::getPossibleMoves(Board *board, std::string from){
    std::set<std::string> validMoves;
    validMoves = board->getValidMoves(from, KNIGHT);
    return validMoves;
}


/*
date: 21-12-2020
File: Pawn.cpp
Author : Facundo Martin Cabrera
Email: cabre94@hotmail.com facundo.cabrera@ib.edu.ar
GitHub: https://github.com/cabre94
GitLab: https://gitlab.com/cabre94
Description:
*/

#include "Pawn.hpp"

Pawn::Pawn(PieceColour C):Piece(C,PAWN,"PAWN") {}

Pawn::~Pawn(){}

bool Pawn::validMove(std::string newPos){
    // TODO completar funcion
    return true;
}

void Pawn::printPiece(){
    if(colour == WHITE)
        std::cout << "♙";
        // std::cout << "\u2659";
    else
        std::cout << "♟︎";
        // std::cout << "\u265F";
}

std::set<std::string> Pawn::getPossibleMoves(Board *board, std::string from){
    std::set<std::string> validMoves;
    validMoves = board->getValidMoves(from, PAWN);
    return validMoves;
}

/*
date: 21-12-2020
File: Rook.cpp
Author : Facundo Martin Cabrera
Email: cabre94@hotmail.com facundo.cabrera@ib.edu.ar
GitHub: https://github.com/cabre94
GitLab: https://gitlab.com/cabre94
Description:
*/

#include "Rook.hpp"

Rook::Rook(PieceColour C):Piece(C,ROOK,"ROOK"){}

Rook::~Rook(){}

bool Rook::validMove(std::string newPos){
    // TODO completar funcion
    return true;
}

void Rook::printPiece(){
    if(colour == WHITE)
        std::cout << "♖";
        // std::cout << "\u2659";
    else
        std::cout << "♜";
        // std::cout << "\u265F";
}

std::set<std::string> Rook::getPossibleMoves(Board *board, std::string from){
    std::set<std::string> validMoves;
    validMoves = board->getValidMoves(from, ROOK);
    return validMoves;
}


/*
date: 24-12-2020
File: Champion.cpp
Author : Facundo Martin Cabrera
Email: cabre94@hotmail.com facundo.cabrera@ib.edu.ar
GitHub: https://github.com/cabre94
GitLab: https://gitlab.com/cabre94
Description:
*/

#include "Champion.hpp"

Champion::Champion(PieceColour C):Piece(C,CHAMPION,"CHAMPION"){}

Champion::~Champion(){}

bool Champion::validMove(std::string newPos){
    // TODO completar funcion
    return true;
}

void Champion::printPiece(){
    if(colour == WHITE)
        std::cout << "⚪♽";
        // std::cout << "\u2659";
    else
        std::cout << "⚫♼";
        // std::cout << "\u265F";
}

std::set<std::string> Champion::getPossibleMoves(Board *board, std::string from){
    std::set<std::string> validMoves;
    validMoves = board->getValidMoves(from, CHAMPION);
    return validMoves;
}
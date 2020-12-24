/*
date: 28-11-2020
File: Piece.cpp
Author : Facundo Martin Cabrera
Email: cabre94@hotmail.com facundo.cabrera@ib.edu.ar
GitHub: https://github.com/cabre94
GitLab: https://gitlab.com/cabre94
Description:
*/

#include "Piece.hpp"


Piece::Piece(PieceColour C, PieceType T, std::string N) : colour(C), type(T), name(N) {}

Piece::~Piece(){}

PieceType Piece::getType(){
    return type;
}

PieceColour Piece::getColour(){
    return colour;
}

std::string Piece::getName(){
    return name;
}



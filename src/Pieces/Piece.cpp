/*
date: 28-11-2020
File: Piece.cpp
Author : Facundo Martin Cabrera
Email: cabre94@hotmail.com facundo.cabrera@ib.edu.ar
GitHub: https://github.com/cabre94
GitLab: https://gitlab.com/cabre94
Description:
*/

#include "Piece.h"


Piece::Piece(PieceColor C, PieceType T, std::string N) : color(C), type(T), name(N) {}

Piece::~Piece(){}

PieceType Piece::getType(){
    return type;
}

PieceColor Piece::getColor(){
    return color;
}

std::string Piece::getName(){
    return name;
}
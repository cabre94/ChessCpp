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
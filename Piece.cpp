/*
date: 28-11-2020
File: Piece.cpp
Author : Facundo Martin Cabrera
Email: cabre94@hotmail.com facundo.cabrera@ib.edu.ar
GitHub: https://github.com/cabre94
GitLab: https://gitlab.com/cabre94
Description:
*/

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <sstream>

/*
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!LAS PIEZAS SE VEN DE UN COLOR AL REVES DE LO QUE ES
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
*/

// #include "Board.cpp"

class Board;


enum PieceColour{NONE, WHITE, BLACK};

enum State{CHECK, CHECKMATE, NORMAL};

enum PieceType{KING, QUEEN, BISHOP, KNIGHT, ROOK, PAWN};


class Piece{
private:
    
public:
    Piece(PieceColour C, PieceType T);	//Default constructor
    virtual ~Piece();

    // Piece(const Piece &) = default;	//Copy constructor
    // Piece &operator=(const Piece &) = default;	//Copy assignment
    // Piece(Piece &&) = default;	//Move constructor
    // Piece &operator=(Piece &&) = default;	// Move assignment

    // Color de la pieza
    PieceColour colour;
    PieceType type;

    std::string pos; // ! Chequear si uso esto

    Board* board;   // ! En vez de tener cada pieza el puntero a tablero, se lo puedo pasar como argumento

    PieceType getType();    // TODO usar const?
    PieceColour getColour();

    virtual bool validMove(std::string newPos) = 0;

    virtual void printPiece() = 0;


};

Piece::Piece(PieceColour C, PieceType T) : colour(C), type(T) {}

Piece::~Piece(){}

PieceType Piece::getType(){
    return type;
}

PieceColour Piece::getColour(){
    return colour;
}

/*
PEON
*/

class Pawn : public Piece{
public:
    Pawn(PieceColour C);
    ~Pawn();

    bool validMove(std::string newPos);

    void printPiece();
};

Pawn::Pawn(PieceColour C):Piece(C,PAWN){}

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

/*
TORRE
*/

class Rook : public Piece{
public:
    Rook(PieceColour C);
    ~Rook();

    bool validMove(std::string newPos);

    void printPiece();
};

Rook::Rook(PieceColour C):Piece(C,ROOK){}

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

/*
CABALLO
*/
class Knight : public Piece{
public:
    Knight(PieceColour C);
    ~Knight();

    bool validMove(std::string newPos);

    void printPiece();
};

Knight::Knight(PieceColour C):Piece(C,KNIGHT){}

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

/*
ALFIL
*/

class Bishop : public Piece{
public:
    Bishop(PieceColour C);
    ~Bishop();

    bool validMove(std::string newPos);

    void printPiece();
};

Bishop::Bishop(PieceColour C):Piece(C,BISHOP){}

Bishop::~Bishop(){}

bool Bishop::validMove(std::string newPos){
    // TODO completar funcion
    return true;
}

void Bishop::printPiece(){
    if(colour == WHITE)
        std::cout << "♗";
        // std::cout << "\u2659";
    else
        std::cout << "♝";
        // std::cout << "\u265F";
}

/*
REINA
*/

class Queen : public Piece{
public:
    Queen(PieceColour C);
    ~Queen();

    bool validMove(std::string newPos);

    void printPiece();
};

Queen::Queen(PieceColour C):Piece(C,QUEEN){}

Queen::~Queen(){}

bool Queen::validMove(std::string newPos){
    // TODO completar funcion
    return true;
}

void Queen::printPiece(){
    if(colour == WHITE)
        std::cout << "♕";
        // std::cout << "\u2659";
    else
        std::cout << "♛";
        // std::cout << "\u265F";
}

/*
REY
*/

class King : public Piece{
public:
    King(PieceColour C);
    ~King();

    bool validMove(std::string newPos);

    void printPiece();
};

King::King(PieceColour C):Piece(C,KING){}

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














// int main(int argc, const char** argv){
    
//     Colour color;
//     color = WHITE;

//     std::cout << color << std::endl;

//     return 0;
// }
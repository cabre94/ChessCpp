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

// enum MoveType{HORIZONTAL, VERTICAL, DIAGONAL, L, FORWARD, ONESTEP};


class Piece{
private:
    
public:
    Piece(PieceColour C, PieceType T, std::string N);	//Default constructor
    virtual ~Piece();

    // Piece(const Piece &) = default;	//Copy constructor
    // Piece &operator=(const Piece &) = default;	//Copy assignment
    // Piece(Piece &&) = default;	//Move constructor
    // Piece &operator=(Piece &&) = default;	// Move assignment

    // Color de la pieza
    PieceColour colour;
    PieceType type;
    std::string name;

    std::string pos; // ! Chequear si uso esto

    Board* board;   // ! En vez de tener cada pieza el puntero a tablero, se lo puedo pasar como argumento

    PieceType getType();    // TODO usar const?
    PieceColour getColour();
    std::string getName();

    virtual bool validMove(std::string newPos) = 0; //Chequear si la use

    virtual std::set<std::string> getPossibleMoves(Board *board, std::string from) = 0;

    virtual void printPiece() = 0;


};

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
/*
PEON
*/

class Pawn : public Piece{
public:
    Pawn(PieceColour C);
    ~Pawn();

    bool validMove(std::string newPos);

    void printPiece();
    std::string getName();

    std::set<std::string> getPossibleMoves(Board  *board, std::string from);
};

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

/*
TORRE
*/

class Rook : public Piece{
public:
    Rook(PieceColour C);
    ~Rook();

    bool validMove(std::string newPos);

    void printPiece();

    std::set<std::string> getPossibleMoves(Board *board, std::string from);
};

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

/*
CABALLO
*/
class Knight : public Piece{
public:
    Knight(PieceColour C);
    ~Knight();

    bool validMove(std::string newPos);

    void printPiece();

    std::set<std::string> getPossibleMoves(Board *board, std::string from);
};

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

/*
ALFIL
*/

class Bishop : public Piece{
public:
    Bishop(PieceColour C);
    ~Bishop();

    bool validMove(std::string newPos);

    void printPiece();

    std::set<std::string> getPossibleMoves(Board *board, std::string from);
};

Bishop::Bishop(PieceColour C):Piece(C,BISHOP,"BISHOP"){}

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

std::set<std::string> Bishop::getPossibleMoves(Board *board, std::string from){
    std::set<std::string> validMoves;
    validMoves = board->getValidMoves(from, BISHOP);
    return validMoves;
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

    std::set<std::string> getPossibleMoves(Board *board, std::string from);
};

Queen::Queen(PieceColour C):Piece(C,QUEEN,"QUEEN"){}

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

std::set<std::string> Queen::getPossibleMoves(Board *board, std::string from){
    std::set<std::string> validMoves;
    validMoves = board->getValidMoves(from, QUEEN);
    return validMoves;
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

    std::set<std::string> getPossibleMoves(Board *board, std::string from);
};

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



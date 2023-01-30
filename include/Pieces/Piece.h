#ifndef PIECE_H
#define PIECE_H

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <cstdlib>
#include <sstream>

enum PieceType{KING, QUEEN, BISHOP, KNIGHT, ROOK, PAWN, CHAMPION, MAGICIAN};


// #include "Board.h"

class Board;

enum PieceColor{NONE, WHITE, BLACK};
enum State{CHECK, CHECKMATE, NORMAL};       //!
// enum PieceType{KING, QUEEN, BISHOP, KNIGHT, ROOK, PAWN};

// enum MoveType{HORIZONTAL, VERTICAL, DIAGONAL, L, FORWARD, ONESTEP};


class Piece{
protected:
    PieceColor color;
    PieceType type;
    std::string name;
    
public:
    Piece(PieceColor C, PieceType T, std::string N);	//Default constructor
    virtual ~Piece();

    Piece(const Piece &) = delete;	//Copy constructor
    Piece &operator=(const Piece &) = delete;	//Copy assignment
    Piece(Piece &&) = delete;	//Move constructor
    Piece &operator=(Piece &&) = delete;	// Move assignment

    PieceType getType();
    PieceColor getColor();
    std::string getName();

    virtual std::set<std::string> getPossibleMoves(Board *board, std::string from) = 0;

    virtual void printPiece() = 0;

};

#endif // PIECE_H

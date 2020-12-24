#ifndef PIECE_HPP
#define PIECE_HPP

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <cstdlib>
#include <sstream>

enum PieceType{KING, QUEEN, BISHOP, KNIGHT, ROOK, PAWN, CHAMPION, MAGICIAN};


#include "Board.hpp"

/*
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!LAS PIEZAS SE VEN DE UN COLOR AL REVES DE LO QUE ES
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
*/

class Board;

enum PieceColour{NONE, WHITE, BLACK};
enum State{CHECK, CHECKMATE, NORMAL};       //!
// enum PieceType{KING, QUEEN, BISHOP, KNIGHT, ROOK, PAWN};

// enum MoveType{HORIZONTAL, VERTICAL, DIAGONAL, L, FORWARD, ONESTEP};


class Piece{
protected:
    PieceColour colour;
    PieceType type;
    std::string name;
    
public:
    Piece(PieceColour C, PieceType T, std::string N);	//Default constructor
    virtual ~Piece();

    // Piece(const Piece &) = default;	//Copy constructor
    // Piece &operator=(const Piece &) = default;	//Copy assignment
    // Piece(Piece &&) = default;	//Move constructor
    // Piece &operator=(Piece &&) = default;	// Move assignment

    // Color de la pieza
    

    std::string pos; // ! Chequear si uso esto

    Board* board;   // ! En vez de tener cada pieza el puntero a tablero, se lo puedo pasar como argumento

    PieceType getType();    // TODO usar const?
    PieceColour getColour();
    std::string getName();

    // virtual bool validMove(std::string newPos) = 0; //Chequear si la use

    virtual std::set<std::string> getPossibleMoves(Board *board, std::string from) = 0;

    virtual void printPiece() = 0;


};

#include "Pawn.hpp"
#include "Rook.hpp"
#include "Knight.hpp"
#include "Bishop.hpp"
#include "Queen.hpp"
#include "King.hpp"
#include "Magician.hpp"
#include "Champion.hpp"

#endif

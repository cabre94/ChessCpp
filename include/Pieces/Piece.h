#ifndef PIECE_H
#define PIECE_H

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <cstdlib>
#include <sstream>

#include "Types.h"

// enum PieceType{KING, QUEEN, BISHOP, KNIGHT, ROOK, PAWN, CHAMPION, MAGICIAN}; // TODO

class Board;

// enum PieceColor{NONE, WHITE, BLACK};
enum State{CHECK, CHECKMATE, NORMAL};       //!

class Piece{
protected:
    const PlayerID player_id;	// TODO const
    std::string name;
	Position pos;
    
public:
    Piece(PlayerID player_id_, std::string name_, Position pos_) 
		: player_id(player_id_), name(name_), pos(pos_) {}
    virtual ~Piece() {}

    Piece(const Piece &) = delete;				// Copy constructor
    Piece &operator=(const Piece &) = delete;	// Copy assignment
    Piece(Piece &&) = delete;					// Move constructor
    Piece &operator=(Piece &&) = delete;		// Move assignment

    PlayerID getPlayerID() const {return player_id;};
    std::string getName() const {return name;};
	Position getPosition() const {return pos;}

    virtual std::set<std::string> getPossibleMoves(const Board *board) const = 0;
    virtual void printPiece() const = 0;
};

#endif // PIECE_H

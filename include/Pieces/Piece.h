#pragma once

#include <cstdlib>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>

#include "Positions/Position.h"
#include "Types.h"

namespace chess {

class Board;

enum State { CHECK, CHECKMATE, NORMAL }; // TODO

class Piece {
public:
    Piece(PlayerID player_id_, std::string name_, Position pos_)
        : player_id(player_id_), name(name_), pos(pos_) {}
    virtual ~Piece() {}

    Piece(const Piece &) = delete;            // Copy constructor
    Piece &operator=(const Piece &) = delete; // Copy assignment
    Piece(Piece &&) = delete;                 // Move constructor
    Piece &operator=(Piece &&) = delete;      // Move assignment

    PlayerID getPlayerID() const { return player_id; };
    std::string getName() const { return name; };
    Position getPosition() const { return pos; }

    virtual std::set<Position> getPossibleMoves(const Board *board) const = 0;
    virtual void printPiece() const = 0;

    friend std::ostream &operator<<(std::ostream &os, const Piece &piece) {
        os << piece.symbol;
        return os;
    }

protected:
    const PlayerID player_id;
    std::string name;
    Position pos;
};

} // namespace chess
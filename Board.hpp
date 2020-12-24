#ifndef BOARD_HPP
#define BOARD_HPP

#include <map>
#include <set>
#include <iostream>
#include <string>

#include "Piece.hpp"
// #include "Position.cpp"         //! No lo use al final

class Piece;

class Board{
public:
    Board();	//Default constructor
    virtual ~Board();

    Board(const Board &) = default;	//Copy constructor
    Board &operator=(const Board &) = default;	//Copy assignment
    Board(Board &&) = default;	//Move constructor
    Board &operator=(Board &&) = default;	// Move assignment

    virtual void printBoard() = 0;
    virtual void printPositions() = 0;      // ! Creo que no hace falta que sea virtual
    virtual void printPosAndPieces() = 0;
    // virtual int* string2pos(std::string str) = 0;

    virtual bool makeMove(std::string from, std::string to) = 0;

    virtual std::set<std::string> getValidMoves(std::string from, PieceType T) = 0;

    bool askWinner();

    bool isWhiteInCheck();
    bool isBlackInCheck();

protected:
    bool stringInSet(std::set<std::string> set, std::string str);

    

    std::map<std::string, Piece*> whitePieces;
    std::map<std::string, Piece*> blackPieces;

    std::set<std::string> allWhiteMoves;
    std::set<std::string> allBlackMoves;

    std::string whiteKingPos, blackKingPos;

    bool whiteTurn;
    bool gameEnded;
    bool whiteInCheck, blackInCheck;
};

#include "ChessBoard.hpp"

#endif
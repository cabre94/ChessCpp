/*
date: 23-12-2020
File: ChessGame.cpp
Author : Facundo Martin Cabrera
Email: cabre94@hotmail.com facundo.cabrera@ib.edu.ar
GitHub: https://github.com/cabre94
GitLab: https://gitlab.com/cabre94
Description:
*/

#include "ChessGame.hpp"

ChessGame::ChessGame(){
    std::cout << "Choose chess variant" << std::endl;
    std::cout << "n: Normal Chess game" << std::endl;
    std::cout << "b: ButterflyChess - Normal board chess with butterfly distribution" << std::endl;
    std::cout << "p: PawnChess -Normal board chess with Pawn Game distribution" << std::endl;

    char c;
    std::cin >> c;

    boardPtr = new ChessBoard(c);
}

ChessGame::~ChessGame(){
    delete boardPtr;
}

void ChessGame::play(){

    while(!boardPtr->askWinner()){
        // system("clear");

        bool succesMove;

        std::string from, to;

        boardPtr->printPosAndPieces();
        boardPtr->printBoard();

        printCheckMessage();

        succesMove = boardPtr->makeMove(from, to);
    }
}

void ChessGame::printCheckMessage(){
    if(boardPtr->isWhiteInCheck())
        std::cout << "White king is in check" << std::endl;
    if(boardPtr->isBlackInCheck())
        std::cout << "Black king is in check" << std::endl;
}
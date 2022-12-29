/*
date: 28-11-2020
File: Board.cpp
Author : Facundo Martin Cabrera
Email: cabre94@hotmail.com facundo.cabrera@ib.edu.ar
GitHub: https://github.com/cabre94
GitLab: https://gitlab.com/cabre94
Description:
*/

#include "Board.hpp"


Board::Board(){
    gameEnded = false;
    whiteTurn = true;
    whiteInCheck = false;
    blackInCheck = false;
}

Board::~Board(){
}

bool Board::stringInSet(std::set<std::string> set, std::string str){
    return bool(set.count(str));
}

bool Board::askWinner(){
    return gameEnded;
}

bool Board::isWhiteInCheck(){
    return whiteInCheck;
}

bool Board::isBlackInCheck(){
    return blackInCheck;
}
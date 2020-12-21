/*
date: 19-12-2020
File: main.cpp
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

#include "Board.cpp"
// #include "Piece.cpp"

int main(int argc, const char** argv){
    
    Board* ptr;

    ptr = new ChessBoard;
    ptr->printBoard();
    ptr->printPositions();

    int counter = 0;

    while(counter < 5){
        bool succesMove;

        std::string from, to;

        std::cout << "From: ";
        std::cin >> from;
        std::cout << "To: ";
        std::cin >> to;

        succesMove = ptr->makeMove(from, to);

        ptr->printPositions();
        ptr->printBoard();

        if(succesMove)
            counter++;
    }

    // ptr->printBoard();
    // ptr->printPositions();
    
    delete ptr;

    // ptr = new T2;
    // ptr->print();

    return 0;
}
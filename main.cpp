/*
date: 19-12-2020
File: main.cpp
Author : Facundo Martin Cabrera
Email: cabre94@hotmail.com facundo.cabrera@ib.edu.ar
GitHub: https://github.com/cabre94
GitLab: https://gitlab.com/cabre94
Description:
*/


#include "ChessGame.h"
#include <cstdlib>

// #include "Board.cpp"
// #include "Piece.cpp"
// #include "ChessBoard.cpp"

// int main(int argc, const char** argv){
    
//     Board* ptr;
//     // ChessBoard* ptr;

//     ptr = new ChessBoard;

//     // system("clear");
//     // ptr->printBoard();
//     // ptr->printPositions();

//     int counter = 0;

//     while(!ptr->askWinner()){
//         // system("clear");

//         bool succesMove;

//         std::string from, to;

//         ptr->printPosAndPieces();
//         ptr->printBoard();

//         // std::cout << "From: ";
//         // std::cin >> from;
//         // std::cout << "To: ";
//         // std::cin >> to;

//         succesMove = ptr->makeMove(from, to);

//         if(succesMove)
//             counter++;

//     }

//     // ptr->printBoard();
//     // ptr->printPositions();
    
//     delete ptr;

//     // ptr = new T2;
//     // ptr->print();

//     return 0;
// }





int main(int argc, const char** argv){
    
    ChessGame game;

    game.play();

    return 0;
}
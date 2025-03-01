#include <cstdlib>

// #include "Board.cpp"
#include "ChessGame.h"
#include "ChessBoard.h"
#include "Piece.h"
#include "RealPlayer.h"

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

int main(int argc, const char **argv) {

    // ChessGame game;

    // game.play();

    chess::Board *board = new chess::ChessBoard(8, 8);

    chess::RealPlayer player_white(WHITE);
    chess::RealPlayer player_black(BLACK);

    board->addPlayerPieces(player_white.getPieces());
    board->addPlayerPieces(player_black.getPieces());

    board->createPices('n');

    board->printBoard();

    delete board;

    return 0;
}
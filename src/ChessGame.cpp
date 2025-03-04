#include "ChessGame.h"
#include "Board.h"
#include "ChessBoard.h"
#include "Position.h"

namespace chess {

ChessGame::ChessGame() {
    std::cout << "Choose chess variant" << std::endl;
    std::cout << "n: Normal Chess game" << std::endl;
    std::cout << "b: ButterflyChess - Normal board chess with butterfly distribution" << std::endl;
    std::cout << "p: PawnChess -Normal board chess with Pawn Game distribution" << std::endl;
    std::cout << "c: PawnChess -Normal board chess with Champion and Magician pieces" << std::endl;

    char c;
    std::cin >> c;

    boardPtr = new ChessBoard(8, 8);
}

ChessGame::~ChessGame() { delete boardPtr; }

void ChessGame::play() {

    while (!boardPtr->askWinner()) {
        // system("clear");

        bool succesMove;

        std::string from, to;

        boardPtr->printPosAndPieces();
        boardPtr->printBoard();

        printCheckMessage();

        // succesMove = boardPtr->makeMove(from, to);
    }
}

void ChessGame::printCheckMessage() const {
    if (boardPtr->isWhiteInCheck())
        std::cout << "White king is in check" << std::endl;
    if (boardPtr->isBlackInCheck())
        std::cout << "Black king is in check" << std::endl;
}

} // namespace chess
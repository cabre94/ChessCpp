#include <gtest/gtest.h>

#include <algorithm>
#include <cstdint>
#include <set>
#include <string>

#include "Boards/ChessBoard.h"
#include "Positions/Position.h"

// #include "Champion.h"
// #include "King.h"
// #include "Knight.h"
// #include "Magician.h"
// #include "Pawn.h"
// #include "Queen.h"
// #include "Rook.h"

// static std::string toLower(const std::string &str) {
//     std::string lowerStr = str; // Copiar el string original
//     std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(),
//                    [](unsigned char c) { return std::tolower(c); });
//     return lowerStr;
// }

static void printSetPositions(const std::set<chess::Position> &positions) {
    for (const auto &pos : positions) {
        std::cout << pos << " "; // Usa el operador << definido en Position
    }
    std::cout << std::endl;
}

TEST(ChessBoard, getParallelMoves) {
    chess::ChessBoard board;

    std::set<chess::Position> moves;
    chess::Position pos(0, 0);

    for (uint32_t r = 0; r < chess::ChessBoard::N_ROW; r++) {
        for (uint32_t c = 0; c < chess::ChessBoard::N_COL; c++) {
            // Create current position
            pos = chess::Position(r, c);

            moves = board.getParallelMoves(pos, chess::WHITE);
            // moves.size()

            printSetPositions(moves);
        }
    }
}
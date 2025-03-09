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

[[maybe_unused]] static void printSetPositions(const chess::Position &c_pos,
                                               const std::set<chess::Position> &positions) {
    std::cout << c_pos << " --> ";
    for (const auto &pos : positions) {
        std::cout << pos << " "; // Usa el operador << definido en Position
    }
    std::cout << std::endl;
}

static std::set<chess::Position> expectedParallelMovesEmptyBoard(uint32_t r, uint32_t c) {
    std::set<chess::Position> exp_set;

    // Add positions in the same row
    for (uint32_t cc = 0; cc < chess::ChessBoard::N_COL; cc++) {
        if (cc != c)
            exp_set.insert(chess::Position(r, cc));
    }

    // Add positions in the same column
    for (uint32_t rr = 0; rr < chess::ChessBoard::N_ROW; rr++) {
        if (rr != r)
            exp_set.insert(chess::Position(rr, c));
    }

    return exp_set;
}
[[maybe_unused]] static std::set<chess::Position> expectedDiagonalMovesEmptyBoard(uint32_t r,
                                                                                  uint32_t c) {
    std::set<chess::Position> exp_set;

    // Diagonal movement ↘ and ↖ (r+c constant)
    for (uint32_t i = 0; i < chess::ChessBoard::N_ROW; i++) {
        int32_t new_r = static_cast<int32_t>(r) + (i - r);
        int32_t new_c = static_cast<int32_t>(c) + (i - r);
        if (new_r >= 0 && new_r < static_cast<int32_t>(chess::ChessBoard::N_ROW) && new_c >= 0 &&
            new_c < static_cast<int32_t>(chess::ChessBoard::N_COL) &&
            (new_r != static_cast<int32_t>(r) || new_c != static_cast<int32_t>(c))) {
            exp_set.insert(chess::Position(new_r, new_c));
        }
    }

    // Diagonal movement ↙ and ↗ (constant r-c)
    for (uint32_t i = 0; i < chess::ChessBoard::N_ROW; i++) {
        int32_t new_r = static_cast<int32_t>(r) + (i - r);
        int32_t new_c = static_cast<int32_t>(c) - (i - r);
        if (new_r >= 0 && new_r < static_cast<int32_t>(chess::ChessBoard::N_ROW) && new_c >= 0 &&
            new_c < static_cast<int32_t>(chess::ChessBoard::N_COL) &&
            (new_r != static_cast<int32_t>(r) || new_c != static_cast<int32_t>(c))) {
            exp_set.insert(chess::Position(new_r, new_c));
        }
    }

    return exp_set;
}

TEST(ChessBoard, getParallelMoves) {
    chess::ChessBoard board;

    std::set<chess::Position> moves, expected_moves;
    chess::Position pos(0, 0);

    for (uint32_t r = 0; r < chess::ChessBoard::N_ROW; r++) {
        for (uint32_t c = 0; c < chess::ChessBoard::N_COL; c++) {
            // Get expected set of valid moves for this position
            expected_moves = expectedParallelMovesEmptyBoard(r, c);

            // Create current position
            pos = chess::Position(r, c);

            // Get moves from board
            moves = board.getParallelMoves(pos, chess::WHITE);

            printSetPositions(pos, moves);
            EXPECT_EQ(moves, expected_moves) << "Error en posición (" << r << ", " << c << ")";
        }
    }
}

TEST(ChessBoard, getDiagonalMoves) {
    chess::ChessBoard board;

    std::set<chess::Position> moves, expected_moves;
    chess::Position pos(0, 0);

    for (uint32_t r = 0; r < chess::ChessBoard::N_ROW; r++) {
        for (uint32_t c = 0; c < chess::ChessBoard::N_COL; c++) {
            // Get expected set of valid moves for this position
            expected_moves = expectedDiagonalMovesEmptyBoard(r, c);

            // Create current position
            pos = chess::Position(r, c);

            // Get moves from board
            moves = board.getDiagonalMoves(pos, chess::WHITE);

            printSetPositions(pos, moves);
            EXPECT_EQ(moves, expected_moves) << "Error en posición (" << r << ", " << c << ")";
        }
    }
}
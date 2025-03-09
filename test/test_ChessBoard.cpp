#include <gtest/gtest.h>

#include <algorithm>
#include <cstdint>
#include <set>
#include <string>

#include "Boards/ChessBoard.h"
#include "Pieces/Piece.h"
#include "Positions/Position.h"

class TestChessBoard : public chess::ChessBoard {
public:
    void testInitializePieces() { initializePieces(); }
    chess::Piece *getPiece(uint32_t r, uint32_t c) { return ChessBoard::getPiece(r, c); }
};

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

static std::set<chess::Position> expectedDiagonalMovesEmptyBoard(uint32_t r, uint32_t c) {
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

static std::set<chess::Position> expectedLShapeEmptyBoard(uint32_t r, uint32_t c,
                                                          const std::vector<uint16_t> &deltas) {
    std::set<chess::Position> exp_set;

    if (deltas.size() != 2) {
        throw std::invalid_argument(
            "expectedLShapeEmptyBoard requiere exactamente dos valores en deltas.");
    }

    int32_t dr = static_cast<int32_t>(deltas[0]);
    int32_t dc = static_cast<int32_t>(deltas[1]);

    std::vector<std::pair<int32_t, int32_t>> directions = {
        {dr, dc}, {dc, dr}, {-dr, dc}, {-dc, dr}, {dr, -dc}, {dc, -dr}, {-dr, -dc}, {-dc, -dr}};

    for (const auto &[delta_r, delta_c] : directions) {
        int32_t new_r = static_cast<int32_t>(r) + delta_r;
        int32_t new_c = static_cast<int32_t>(c) + delta_c;

        if (new_r >= 0 && new_r < static_cast<int32_t>(chess::ChessBoard::N_ROW) && new_c >= 0 &&
            new_c < static_cast<int32_t>(chess::ChessBoard::N_COL)) {
            exp_set.insert(chess::Position(new_r, new_c));
        }
    }

    return exp_set;
}

static std::set<chess::Position>
expectedForwardMovesEmptyBoard(uint32_t r, uint32_t c, const std::vector<int16_t> &forward_dir,
                               bool first, bool consider_diagonals = false) {
    std::set<chess::Position> exp_set;

    if (forward_dir.size() != 2) {
        throw std::invalid_argument(
            "expectedForwardMovesEmptyBoard requiere exactamente dos valores en forward_dir.");
    }

    int32_t dr = static_cast<int32_t>(forward_dir[0]);
    int32_t dc = static_cast<int32_t>(forward_dir[1]);

    // Movimiento hacia adelante (uno o dos pasos según "first")
    uint32_t max_steps = first ? 2 : 1;
    for (uint32_t step = 1; step <= max_steps; ++step) {
        int32_t new_r = static_cast<int32_t>(r) + step * dr;
        int32_t new_c = static_cast<int32_t>(c) + step * dc;

        if (new_r >= 0 && new_r < static_cast<int32_t>(chess::ChessBoard::N_ROW) && new_c >= 0 &&
            new_c < static_cast<int32_t>(chess::ChessBoard::N_COL)) {
            exp_set.insert(chess::Position(new_r, new_c));
        }
    }

    if (!consider_diagonals)
        return exp_set;

    // Capturas diagonales
    constexpr int32_t diagonal_offsets[2] = {-1, 1};

    for (const auto &offset : diagonal_offsets) {
        int32_t diagonal_r = static_cast<int32_t>(r) + dr;
        int32_t diagonal_c = static_cast<int32_t>(c) + offset;

        if (diagonal_r >= 0 && diagonal_r < static_cast<int32_t>(chess::ChessBoard::N_ROW) &&
            diagonal_c >= 0 && diagonal_c < static_cast<int32_t>(chess::ChessBoard::N_COL)) {
            exp_set.insert(chess::Position(diagonal_r, diagonal_c));
        }
    }

    return exp_set;
}

static std::set<chess::Position> expectedAllDirectionMovesEmptyBoard(uint32_t r, uint32_t c) {
    std::set<chess::Position> exp_set = expectedParallelMovesEmptyBoard(r, c);
    std::set<chess::Position> exp_diagonal_moves = expectedDiagonalMovesEmptyBoard(r, c);

    exp_set.insert(exp_diagonal_moves.begin(), exp_diagonal_moves.end());

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

            // printSetPositions(pos, moves);
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

            // printSetPositions(pos, moves);
            EXPECT_EQ(moves, expected_moves) << "Error en posición (" << r << ", " << c << ")";
        }
    }
}

TEST(ChessBoard, getLShapeMoves) {
    chess::ChessBoard board;

    std::set<chess::Position> moves, expected_moves;
    chess::Position pos(0, 0);
    std::vector<std::vector<uint16_t>> v_deltas = {{1, 2}, {1, 3}};

    for (const auto &deltas : v_deltas) {
        for (uint32_t r = 0; r < chess::ChessBoard::N_ROW; r++) {
            for (uint32_t c = 0; c < chess::ChessBoard::N_COL; c++) {
                // Get expected set of valid moves for this position
                expected_moves = expectedLShapeEmptyBoard(r, c, deltas);

                // Create current position
                pos = chess::Position(r, c);

                // Get moves from board
                moves = board.getLShapeMoves(pos, chess::WHITE, deltas);

                // printSetPositions(pos, moves);
                EXPECT_EQ(moves, expected_moves) << "Error en posición (" << r << ", " << c << ")";
            }
        }
    }
}

TEST(ChessBoard, getFordwardMoves) {
    chess::ChessBoard board;

    std::set<chess::Position> moves, expected_moves;
    chess::Position pos(0, 0);
    std::vector<std::vector<int16_t>> v_forward_dir = {{1, 0}, {-1, 0}};

    // for (bool first : {false}) {
    for (bool first : {true, false}) {
        for (const auto &forward_dir : v_forward_dir) {
            for (uint32_t r = 0; r < chess::ChessBoard::N_ROW; r++) {
                for (uint32_t c = 0; c < chess::ChessBoard::N_COL; c++) {
                    // Get expected set of valid moves for this position
                    expected_moves = expectedForwardMovesEmptyBoard(r, c, forward_dir, first);

                    // Create current position
                    pos = chess::Position(r, c);

                    // Get moves from board
                    moves = board.getFordwardMoves(pos, chess::WHITE, forward_dir, first);

                    // printSetPositions(pos, moves);
                    // printSetPositions(pos, expected_moves);
                    EXPECT_EQ(moves, expected_moves)
                        << "Error en posición (" << r << ", " << c << ")";
                }
            }
        }
    }
}

TEST(ChessBoard, getAllDirectionMoves) {
    chess::ChessBoard board;

    std::set<chess::Position> moves, expected_moves;
    chess::Position pos(0, 0);

    for (uint32_t r = 0; r < chess::ChessBoard::N_ROW; r++) {
        for (uint32_t c = 0; c < chess::ChessBoard::N_COL; c++) {
            // Get expected set of valid moves for this position
            expected_moves = expectedAllDirectionMovesEmptyBoard(r, c);

            // Create current position
            pos = chess::Position(r, c);

            // Get moves from board
            moves = board.getAllDirectionMoves(pos, chess::WHITE);

            // printSetPositions(pos, moves);
            EXPECT_EQ(moves, expected_moves) << "Error en posición (" << r << ", " << c << ")";
        }
    }
}

TEST(ChessBoard, InitializePiecesTest) {
    TestChessBoard board;
    board.testInitializePieces(); // initialize pieces

    // White pieces
    EXPECT_EQ(board.getPiece(0, 0)->getPlayerID(), chess::WHITE);
    EXPECT_EQ(board.getPiece(0, 1)->getPlayerID(), chess::WHITE);
    EXPECT_EQ(board.getPiece(0, 2)->getPlayerID(), chess::WHITE);
    EXPECT_EQ(board.getPiece(0, 3)->getPlayerID(), chess::WHITE);
    EXPECT_EQ(board.getPiece(0, 4)->getPlayerID(), chess::WHITE);
    EXPECT_EQ(board.getPiece(0, 5)->getPlayerID(), chess::WHITE);
    EXPECT_EQ(board.getPiece(0, 6)->getPlayerID(), chess::WHITE);
    EXPECT_EQ(board.getPiece(0, 7)->getPlayerID(), chess::WHITE);

    for (uint32_t c = 0; c < chess::ChessBoard::N_COL; ++c) {
        EXPECT_EQ(board.getPiece(1, c)->getPlayerID(), chess::WHITE);
    }
}
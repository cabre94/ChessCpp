#pragma once

#include <cassert>
#include <string>

#include "Boards/Board.h"
#include "Pieces/Piece.h"
#include "Positions/Position.h"

namespace chess {

class ChessBoard : public Board {
public:
    // ChessBoard(uint16_t nRow_, uint16_t nCol_);
    ChessBoard();
    ~ChessBoard();

    // Funciones virtuales
    void printBoard() const override;
    // void printPositions();
    // void printPosAndPieces() const override;

    // bool makeMove(Position from, Position to) override;

    // void createPices(const char c = 'n') override;

    // TODO sacar
    // std::set<Position> getValidMoves(Position pos) const override; // TODO Sacar esto

    std::set<Position> getParallelMoves(const Position &pos,
                                        const PlayerID player_id) const override;
    std::set<Position> getDiagonalMoves(const Position &pos,
                                        const PlayerID player_id) const override;
    std::set<Position> getLShapeMoves(const Position &pos, const PlayerID player_id,
                                      const std::vector<uint16_t> &deltas) const override;
    std::set<Position> getFordwardMoves(const Position &pos, const PlayerID player_id,
                                        std::vector<int16_t> forward_dir,
                                        bool first = false) const override;
    std::set<Position> getAllDirectionMoves(const Position &pos,
                                            const PlayerID player_id) const override;

protected:
    void clearBoard();

    void initializePieces();
    // void initializePiecesButterfly();
    // void initializePiecesPawnGame();
    // void initializePiecesChampionMagician();

    bool validIdxs(uint32_t r, uint32_t c) const;
    bool validPos(const Position &pos) const;

    Position idx2Pos(const uint32_t r, const uint32_t c) const;

    Piece *getPiece(uint32_t r, uint32_t c) {
        assert(validIdxs(r, c));
        return pieces[r][c];
    }

public:
    static const uint32_t N_ROW = 8;
    static const uint32_t N_COL = 8;

private:
    Piece *pieces[N_ROW][N_COL]; //! No enteindo porque no puedo poner SIZE
};

} // namespace chess
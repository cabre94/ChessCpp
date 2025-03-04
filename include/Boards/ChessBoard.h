#pragma once

#include <string>

#include "Boards/Board.h"
#include "Pieces/Piece.h"
#include "Positions/Position.h"

namespace chess {

class ChessBoard : public Board {
public:
    ChessBoard(uint16_t nRow_, uint16_t nCol_);
    ~ChessBoard();

    // Funciones virtuales
    void printBoard() const override;
    // void printPositions();
    void printPosAndPieces() const override;
    // int* string2pos(Position str);

    bool makeMove(Position from, Position to);

    void createPices(const char c = 'n') override;

    // TODO sacar
    std::set<Position> getValidMoves(Position pos) const override; // TODO Sacar esto

    std::set<Position> getDiagonalMoves(const Position &pos) const override;
    std::set<Position> getParallelMoves(const Position &pos) const override;
    std::set<Position> getLShapeMoves(const Position &pos,
                                      const std::vector<u_int16_t> &deltas) const override;
    std::set<Position> getFordwardMoves(const Position &pos, int direction,
                                        bool first = false) const override;
    std::set<Position> getAllDirectionMoves(const Position &pos) const override;

private:
    void initializePieces();
    // void initializePiecesButterfly();
    // void initializePiecesPawnGame();
    // void initializePiecesChampionMagician();

    void clearBoard();

    void printSet(std::set<Position> moveSet);

    bool posInBoard(int i, int j);

    // Position pos2string(int x, int y);
    Position idx2Position(const uint32_t i, const uint32_t j) const;

    // int position2row(const Position &pos) const;
    // int position2column(const Position &pos) const;

    Piece *getPieceFromIdx(const uint32_t i, const uint32_t j) const;

    // void updatePiecesPositions();
    // void updateAllValidMoves();
    // void updateGameState();

    std::set<Position> getValidMoves(Position from);

    std::set<Position> getPawnMoves(Position from);
    std::set<Position> getRookMoves(Position from);
    std::set<Position> getKnightMoves(Position from);
    std::set<Position> getBishopMoves(Position from);
    std::set<Position> getQueenMoves(Position from);
    std::set<Position> getKingMoves(Position from);
    std::set<Position> getChampionMoves(Position from);
    std::set<Position> getMagicianMoves(Position from);

    // char typeDistribution;
    const uint16_t nRow, nCol;
    Piece *pieces[8][8]; //! No enteindo porque no puedo poner SIZE
    Piece **positions;
};

} // namespace chess
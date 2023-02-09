#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <string>

#include "Board.h"
#include "Piece.h"

class ChessBoard : public Board{
public:
    ChessBoard(uint16_t nRow_, uint16_t nCol_);
    ~ChessBoard();

    

    // Funciones virtuales
    void printBoard() const override;
    // void printPositions();
    void printPosAndPieces() const override;
    // int* string2pos(std::string str);

    bool makeMove(std::string from, std::string to);

	void createPices(const char c = 'n') override;


	// TODO sacar
    std::set<Position> getValidMoves(Position pos) const override;	// TODO Sacar esto


	std::set<Position> getDiagonalMoves(const Position& pos) const override;
	std::set<Position> getParallelMoves(const Position& pos) const override;
	std::set<Position> getLShapeMoves(const Position& pos, const std::vector<u_int16_t>& deltas) const override;
	std::set<Position> getFordwardMoves(const Position& pos, int direction, bool first = false) const override;
	std::set<Position> getAllDirectionMoves(const Position& pos) const override;


private:
    void initializePieces();
    // void initializePiecesButterfly();
    // void initializePiecesPawnGame();
    // void initializePiecesChampionMagician();

    void clearBoard();

    void printSet(std::set<std::string> moveSet);

    bool posInBoard(int i, int j);

    // std::string pos2string(int x, int y);
    Position idx2Position(const uint32_t i, const uint32_t j) const;
    
	int position2row(const Position& pos) const;
    int position2column(const Position& pos) const;

	Piece* getPieceFromIdx(const uint32_t i, const uint32_t j) const;

    // void updatePiecesPositions();
    // void updateAllValidMoves();
    // void updateGameState();

    std::set<std::string> getValidMoves(std::string from);

    std::set<std::string> getPawnMoves(std::string from);
    std::set<std::string> getRookMoves(std::string from);
    std::set<std::string> getKnightMoves(std::string from);
    std::set<std::string> getBishopMoves(std::string from);
    std::set<std::string> getQueenMoves(std::string from);
    std::set<std::string> getKingMoves(std::string from);
    std::set<std::string> getChampionMoves(std::string from);
    std::set<std::string> getMagicianMoves(std::string from);

    // char typeDistribution;
	const uint16_t nRow, nCol;
    Piece* pieces[8][8];    //! No enteindo porque no puedo poner SIZE
	Piece** positions;

};

#endif // CHESSBOARD_H

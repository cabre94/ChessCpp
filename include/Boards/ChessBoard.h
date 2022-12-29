#ifndef CHESSBOARD_HPP
#define CHESSBOARD_HPP

#include <string>

#include "Board.hpp"
#include "Piece.hpp"

class ChessBoard : public Board{
public:
    ChessBoard(char c = 'n');
    ~ChessBoard();

    

    // Funciones virtuales
    void printBoard();
    // void printPositions();
    void printPosAndPieces();
    // int* string2pos(std::string str);

    bool makeMove(std::string from, std::string to);

private:
    void initializePieces();
    void initializePiecesButterfly();
    void initializePiecesPawnGame();
    void initializePiecesChampionMagician();

    void clearBoard();

    void printSet(std::set<std::string> moveSet);

    bool posInBoard(int i, int j);

    std::string pos2string(int x, int y);
    int string2row(std::string str);
    int string2column(std::string str);

    void updatePiecesPositions();
    void updateAllValidMoves();
    void updateGameState();

    std::set<std::string> getValidMoves(std::string from, PieceType T);

    std::set<std::string> getPawnMoves(std::string from);
    std::set<std::string> getRookMoves(std::string from);
    std::set<std::string> getKnightMoves(std::string from);
    std::set<std::string> getBishopMoves(std::string from);
    std::set<std::string> getQueenMoves(std::string from);
    std::set<std::string> getKingMoves(std::string from);
    std::set<std::string> getChampionMoves(std::string from);
    std::set<std::string> getMagicianMoves(std::string from);

    char typeDistribution;
    Piece* pieces[8][8];    //! No enteindo porque no puedo poner SIZE

};

#endif
